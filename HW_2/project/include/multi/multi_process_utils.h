//
// Created by Andrew Kireev on 20.10.2020.
//

#ifndef HW_2_PROJECT_INCLUDE_MULTI_MULTI_PROCESS_UTILS_H_
#define HW_2_PROJECT_INCLUDE_MULTI_MULTI_PROCESS_UTILS_H_

#include <pthread.h>
#include "utils.h"

# define PARENT_PID -5

typedef struct {
    int main_diagonal;
    int side_diagonal;
    pthread_mutex_t mutex;
} Calculation_multi_proc_res;

Calculation_res* multi_process(Matrix* matrix);

#endif  // HW_2_PROJECT_INCLUDE_MULTI_MULTI_PROCESS_UTILS_H_
