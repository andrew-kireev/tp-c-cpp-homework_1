//
// Created by Andrew Kireev on 20.10.2020.
//

#ifndef HW_2_PROJECT_INCLUDE_MULTI_MULTI_PROCESS_UTILS_H_
#define HW_2_PROJECT_INCLUDE_MULTI_MULTI_PROCESS_UTILS_H_

#include <stdio.h>
#include "utils.h"
#include <stdatomic.h>

# define PARENT_PID -5

int create_forks(int num, int *pids);
Calculation_res *create_shared_memory();
Calculation_res* multi_process(char* file_name, int num_forks);


#endif  // HW_2_PROJECT_INCLUDE_MULTI_MULTI_PROCESS_UTILS_H_
