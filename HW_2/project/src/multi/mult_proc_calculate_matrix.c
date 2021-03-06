//
// Created by Andrew Kireev on 20.10.2020.
//

#include "multi/multi_process_utils.h"

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>
#include <sys/wait.h>


int create_forks(int num, int *pids) {
    int pid;

    for (int i = 0; i != num; ++i) {
        if ((pid = fork()) == -1)
            return -1;
        if (pid == 0) {
            return i;
        }
        pids[i] = pid;
    }
    return PARENT_PID;          // Код parent процесса, нужно будет потом добавить enum;
}

Calculation_multi_proc_res *create_shared_memory() {
    size_t page_size = getpagesize();

    Calculation_multi_proc_res *shared_memory = mmap(NULL, page_size, PROT_READ | PROT_WRITE,
                                          MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (!shared_memory) {
        return NULL;
    }
    shared_memory->main_diagonal = 0;
    shared_memory->side_diagonal = 0;
    return shared_memory;
}

int calculate_multi_proc(Matrix* matrix, Calculation_multi_proc_res* res, int proc_number, int procs_amount) {
    int n = matrix->size;
    int line_for_proc = (n / procs_amount);

    int rest = (proc_number + 1) * line_for_proc;
    if (proc_number + 1 == procs_amount) {
        rest = matrix->size;
    }

    for (int i = proc_number * line_for_proc; i != rest; ++i) {
        for (int j = 0; j != n; ++j) {
            if (i == j) {
                pthread_mutex_lock(&res->mutex);
                res->main_diagonal += matrix->matrix[i][j];
                pthread_mutex_unlock(&res->mutex);
            }
            if (n == i + j + 1) {
                pthread_mutex_lock(&res->mutex);
                res->side_diagonal += matrix->matrix[i][j];
                pthread_mutex_unlock(&res->mutex);
            }
        }
    }
    exit(0);
}

int select_proc_num(size_t matrix_size) {
    if (matrix_size < 100)
        return 1;
    if (matrix_size < 1000)
        return 2;
    if (matrix_size < 5000)
        return 3;
    if (matrix_size < 10000)
        return 4;
    if (matrix_size < 20000)
        return 6;
    if (matrix_size < 100000)
        return 7;
    return 10;
}

Calculation_res* multi_process(Matrix* matrix) {
    if (matrix == NULL)
        return NULL;
    int num_forks = select_proc_num(matrix->size);
    int *pids = (int*)malloc(sizeof(int) * num_forks);
    for (int i = 0; i != num_forks; ++i)
        pids[i] = 0;

    Calculation_multi_proc_res* res;

    if ((res = create_shared_memory()) == NULL) {
        free(pids);
        return NULL;
    }

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&res->mutex, &attr);

    int process_number;
    if ((process_number = create_forks(num_forks, pids)) == -1) {
        munmap(res, getpagesize());
        free(pids);
        return NULL;
    }

    if (process_number != PARENT_PID)
        calculate_multi_proc(matrix, res, process_number, num_forks);

    for (int i = 0; i < num_forks; i++) {
        while (waitpid(pids[i], NULL, 0) > 0) {}
    }

    Calculation_res* res_to_return;
    if ((res_to_return = (Calculation_res*)malloc(sizeof(Calculation_res))) == NULL) {
        munmap(res, getpagesize());
        free(pids);
        return NULL;
    }
    res_to_return->main_diagonal = res->main_diagonal;
    res_to_return->side_diagonal = res->side_diagonal;
    munmap(res, getpagesize());

    free(pids);
    return res_to_return;
}

