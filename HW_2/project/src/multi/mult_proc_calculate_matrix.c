//
// Created by Andrew Kireev on 20.10.2020.
//

#include "multi/multi_process_utils.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
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

Calculation_res *create_shared_memory() {
    size_t page_size = getpagesize();

    Calculation_res *shared_memory = mmap(NULL, page_size, PROT_READ | PROT_WRITE,
                                          MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (!shared_memory) {
        return NULL;
    }
    shared_memory->main_diagonal = 0;
    shared_memory->side_diagonal = 0;
    return shared_memory;
}


Calculation_res* multi_process(char* file_name, int num_forks) {
    Matrix* matrix;
    matrix = read_file(file_name);

    Calculation_res *res;

    if (matrix == NULL)
        return NULL;
    if (num_forks > matrix->size)
        num_forks = matrix->size;
    int *pids = (int*)malloc(sizeof(int) * num_forks);
    for (int i = 0; i != num_forks; ++i)
        pids[i] = 0;

    if ((res = create_shared_memory()) == NULL) {
        free_matrix(matrix);
        free(pids);
        return NULL;
    }

    int process_number;
    if ((process_number = create_forks(num_forks, pids)) == -1) {
        free_matrix(matrix);
        free(pids);
        return NULL;
    }
    printf("pid = %d\n", process_number);

    if (process_number != PARENT_PID)
        calculate_multi_proc(matrix, res, process_number, num_forks);

    for (int i = 0; i < num_forks; i++) {
        while (waitpid(pids[i], NULL, 0) > 0) {}
    }

    free_matrix(matrix);
    free(pids);
//    printf("main diagonal = %d\n", res->main_diagonal);
//    printf("main diagonal = %d\n", res->side_diagonal);

    return res;
}

int calculate_multi_proc(Matrix* matrix, Calculation_res* res, int proc_number, int procs_amount) {
    int n = matrix->size;

//    printf("proc_number = %d\n", proc_number);
//    printf("\tproc_amount = %d\n", procs_amount);
//    printf("\tproc_number + (n / procs_amount) = %d\n", procs_amount);

    int rest = (int)(proc_number + 1) * (int)(n / procs_amount);
//    printf("\trest = %d\n", rest);
    if (proc_number + 1 == procs_amount) {
        rest = matrix->size;
    }

//    printf("\trest = %d\n", rest);
//    printf("\ti = %d\n", (int)proc_number * (int)(n / procs_amount));

    for (int i = (int)proc_number * (int)(n / procs_amount); i != rest; ++i) {
        for (int j = 0; j != n; ++j) {
            if (i == j)
                res->main_diagonal += matrix->matrix[i][j];
            if (n == i + j + 1)
                res->side_diagonal += matrix->matrix[i][j];
        }
    }
//    printf("\tmain diagonal = %d\n", res->main_diagonal);
//    printf("\tside diagonal = %d\n", res->side_diagonal);
    exit(0);
}
