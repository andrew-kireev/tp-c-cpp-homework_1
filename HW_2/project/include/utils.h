//
// Created by Andrew Kireev on 18.10.2020.
//

#ifndef HW_1_UTILS_H
#define HW_1_UTILS_H

#include <stdio.h>

typedef struct {
    _Atomic size_t size;
    int *data;
} Matrix;

typedef struct {
    _Atomic int main_diagonal;
    _Atomic int side_diagonal;
} Calculation_res;

# define PARENT_PID -5


void print_matrix(Matrix* matrix);
Matrix* input_matrix();
Calculation_res calculate_matrix(Matrix* matrix);
Matrix* read_file(const char* file_name);
int create_forks(int num, int *pids);
Calculation_res *create_shared_memory();
Calculation_res* multi_process(char* file_name, int num_forks);
int calculate_multi_proc(Matrix* matrix, Calculation_res* res, int proc_number, int procs_amount);

#endif //HW_1_UTILS_H
