//
// Created by Andrew Kireev on 20.10.2020.
//

#include "multi/multi_process_utils.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>


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



Calculation_multi_proc_res* multi_process(char* file_name, int num_forks) {
    Matrix* matrix;
    matrix = read_file(file_name);

    if (matrix == NULL)
        return NULL;
    if ((size_t)num_forks > matrix->size)
        num_forks = matrix->size;
    int *pids = (int*)malloc(sizeof(int) * num_forks);
    for (int i = 0; i != num_forks; ++i)
        pids[i] = 0;

    Calculation_multi_proc_res* res;

    if ((res = create_shared_memory()) == NULL) {
        free_matrix(matrix);
        free(pids);
        return NULL;
    }

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&res->mutex, &attr);

    int process_number;
    if ((process_number = create_forks(num_forks, pids)) == -1) {
        free_matrix(matrix);
        free(pids);
        return NULL;
    }

    if (process_number != PARENT_PID)
        calculate_multi_proc(matrix, res, process_number, num_forks);

    for (int i = 0; i < num_forks; i++) {
        while (waitpid(pids[i], NULL, 0) > 0) {}
    }

    free_matrix(matrix);
    free(pids);
    return res;
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
