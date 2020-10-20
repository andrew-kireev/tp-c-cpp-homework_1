//
// Created by Andrew Kireev on 18.10.2020.
//

#ifndef HW_1_UTILS_H
#define HW_1_UTILS_H

#include <stdio.h>

typedef struct {
    size_t size;
    int *data;
} Matrix;

typedef struct {
    int main_diagonal;
    int side_diagonal;
} Calculation_res;

# define PARENT_PID -5


void print_matrix(Matrix* matrix);
Matrix* input_matrix();
Calculation_res calculate_matrix(Matrix* matrix);
Matrix* read_file(const char* file_name);

#endif //HW_1_UTILS_H
