//
// Created by Andrew Kireev on 20.10.2020.
//

#ifndef HW_2_PROJECT_INCLUDE_MULTI_MULTI_PROCESS_UTILS_H_
#define HW_2_PROJECT_INCLUDE_MULTI_MULTI_PROCESS_UTILS_H_

#include <stdio.h>
#include "utils.h"
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>
#include <pthread.h>

# define PARENT_PID -5

typedef struct {
    int main_diagonal;
    int side_diagonal;
    pthread_mutex_t mutex;
} Calculation__multi_proc_res;

int create_forks(int num, int *pids);
Calculation__multi_proc_res *create_shared_memory();
Calculation__multi_proc_res* multi_process(char* file_name, int num_forks);
int calculate_multi_proc(Matrix* matrix, Calculation__multi_proc_res* res, int proc_number, int procs_amount);

#endif  // HW_2_PROJECT_INCLUDE_MULTI_MULTI_PROCESS_UTILS_H_
