//
// Created by Andrew Kireev on 18.10.2020.
//

#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

Matrix* input_matrix() {
    int size;

    scanf("%d", &size);

    int *data = (int*)malloc(sizeof(int) * size * size);

    int k = 0;
    for (int i = 0; i != size; ++i) {
        for (int j = 0; j != size; ++j) {
            scanf("%d", &data[k]);
            ++k;
        }
    }
    Matrix *matrix = (Matrix*)malloc(sizeof(matrix) * 1);
    matrix->size = size;
    matrix->data = data;
    return matrix;
}

Calculation_res calculate_matrix(Matrix* matrix) {
    Calculation_res res;
    int n = matrix->size;

    res.main_diagonal = 0;
    res.side_diagonal = 0;

    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (i == j)
                res.main_diagonal += matrix->data[i*n+j];
            if (n == i + j + 1)
                res.side_diagonal += matrix->data[i*n+j];
        }
    }
    return res;
}

void print_matrix(Matrix* matrix) {
    int n = matrix->size;
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            printf("%d ", matrix->data[i*n+j]);
        }
        printf("%c", '\n');
    }
}

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

    if (!(matrix->data = (int*)malloc(sizeof(int) * matrix->size * matrix->size))) {
        free(matrix);
        fclose(file);
        return NULL;
    }

    int n = matrix->size;
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != n; ++j) {
            if (fscanf(file, "%d", &matrix->data[i*n+j]) != 1) {
                free(matrix->data);
                free(matrix);
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);
    return matrix;
}

int create_forks(int num, int *pids) {
    int pid;

    for (int i = 0; i != num; ++i) {
        if ((pid = fork()) == -1)
            return -1;
        if (pid == 0) {
            pids[i] = pid;
            return i;
        }
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
    matrix = read_file("/Users/andrewkireev/Documents/GitHub/tp-c-cpp-homework_1/HW_2/tests/test1");

    Calculation_res *res;

    if (num_forks > matrix->size)
        num_forks = matrix->size;
    int *pids = (int*)malloc(sizeof(int) * num_forks);
    for (int i = 0; i != num_forks; ++i)
        pids[i] = 0;

    if ((res = create_shared_memory()) == NULL) {
        free(matrix->data);
        free(matrix);
        free(pids);
        return NULL;
    }

    int process_number;
    if ((process_number = create_forks(num_forks, pids)) == -1) {
        free(matrix->data);
        free(matrix);
        free(pids);
        return NULL;
    }

    if (process_number != PARENT_PID)
        calculate_multi_proc(matrix, res, process_number, num_forks);

    for (int i = 0; i < num_forks; i++) {
        while (waitpid(pids[i], NULL, 0) > 0);
    }

    free(matrix->data);
    free(matrix);
    free(pids);
//    printf("main diagonal = %d\n", res->main_diagonal);
//    printf("main diagonal = %d\n", res->side_diagonal);

    return res;
}

int calculate_multi_proc(Matrix* matrix, Calculation_res* res, int proc_number, int procs_amount){
    int n = matrix->size;

//    printf("proc_number = %d\n", proc_number);
//    printf("proc_number + (n / procs_amount) = %d\n", procs_amount);
    for (int i = proc_number; i != proc_number + (n / procs_amount); ++i) {
        for (int j = 0; j != n; ++j) {
            if (i == j)
                res->main_diagonal += matrix->data[i*n+j];
            if (n == i + j + 1)
                res->side_diagonal += matrix->data[i*n+j];
        }
    }
//    printf("main diagonal = %d\n", res->main_diagonal);
//    printf("main diagonal = %d\n", res->side_diagonal);
    exit(0);
}

