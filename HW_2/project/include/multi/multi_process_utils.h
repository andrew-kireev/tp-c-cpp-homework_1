//
// Created by Andrew Kireev on 20.10.2020.
//

#ifndef HW_2_PROJECT_INCLUDE_MULTI_MULTI_PROCESS_UTILS_H_
#define HW_2_PROJECT_INCLUDE_MULTI_MULTI_PROCESS_UTILS_H_

#include <stdio.h>
#include "types.h"

# define PARENT_PID -5

void print_matrix(Matrix* matrix);
Matrix* input_matrix();
Matrix* read_file(const char* file_name);
int create_forks(int num, int *pids);
Calculation_res *create_shared_memory();
Calculation_res* multi_process(char* file_name, int num_forks);
int calculate_multi_proc(Matrix* matrix, Calculation_res* res, int proc_number, int procs_amount);


#endif  // HW_2_PROJECT_INCLUDE_MULTI_MULTI_PROCESS_UTILS_H_
