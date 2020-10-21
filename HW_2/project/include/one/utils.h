//
// Created by Andrew Kireev on 18.10.2020.
//

#ifndef HW_2_PROJECT_INCLUDE_ONE_UTILS_H_
#define HW_2_PROJECT_INCLUDE_ONE_UTILS_H_

#include <stdio.h>
#include "types.h"

# define PARENT_PID -5

void print_matrix(Matrix* matrix);
Matrix* input_matrix();
Calculation_res calculate_matrix(Matrix* matrix);
Matrix* read_file(const char* file_name);

#endif  // HW_2_PROJECT_INCLUDE_ONE_UTILS_H_
