//
// Created by Andrew Kireev on 20.10.2020.
//

#include "multi/multi_process_utils.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>


Matrix* read_file(const char* file_name) {
    FILE* file;

    file = fopen(file_name, "r");
    if (file == NULL)
        return NULL;

    Matrix* matrix;
    if (!(matrix = (Matrix*)malloc(sizeof(Matrix) * 1))) {
        fclose(file);
        return NULL;
    }

    if (fscanf(file, "%zu", &matrix->size) != 1) {
        free(matrix);
        fclose(file);
        return NULL;
    }

    if (!(matrix->main_diagonal = (int*)malloc(sizeof(int) * matrix->size))) {
        free(matrix);
        fclose(file);
        return NULL;
    }

    if (!(matrix->side_diagonal = (int*)malloc(sizeof(int) * matrix->size))) {
        free(matrix->main_diagonal);
        free(matrix);
        fclose(file);
        return NULL;
    }

    int *tmp_one_row;
    if (!(tmp_one_row = (int*)malloc(sizeof(int) * matrix->size))) {
        free(matrix->main_diagonal);
        free(matrix->side_diagonal);
        free(matrix);
        fclose(file);
        return NULL;
    }

    int n = matrix->size;
    int k_main = 0;
    int k_side = 0;
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != n; ++j) {
            if (fscanf(file, "%d", &tmp_one_row[j]) != 1) {
                free(tmp_one_row);
                free(matrix->main_diagonal);
                free(matrix->side_diagonal);
                free(matrix);
                fclose(file);
                return NULL;
            }
        }
        matrix->main_diagonal[k_main++] = tmp_one_row[i];
        matrix->side_diagonal[k_side++] = tmp_one_row[n - i - 1];
    }

    free(tmp_one_row);
    fclose(file);
    return matrix;
}

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
        free(matrix->main_diagonal);
        free(matrix->side_diagonal);
        free(matrix);
        free(pids);
        return NULL;
    }

    int process_number;
    if ((process_number = create_forks(num_forks, pids)) == -1) {
        free(matrix->main_diagonal);
        free(matrix->side_diagonal);
        free(matrix);
        free(pids);
        return NULL;
    }
    printf("pid = %d\n", process_number);

    if (process_number != PARENT_PID)
        calculate_multi_proc(matrix, res, process_number, num_forks);

    for (int i = 0; i < num_forks; i++) {
        while (waitpid(pids[i], NULL, 0) > 0) {}
    }

    free(matrix->main_diagonal);
    free(matrix->side_diagonal);
    free(matrix);
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
        res->main_diagonal += matrix->main_diagonal[i];

        res->side_diagonal += matrix->side_diagonal[i];
    }
//    printf("\tmain diagonal = %d\n", res->main_diagonal);
//    printf("\tside diagonal = %d\n", res->side_diagonal);
    exit(0);
}
