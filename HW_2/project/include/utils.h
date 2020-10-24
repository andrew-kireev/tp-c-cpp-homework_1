//
// Created by Andrew Kireev on 23.10.2020.
//

#ifndef HW_2_UTILS_H
#define HW_2_UTILS_H

#include <stdlib.h>
#include <stdatomic.h>

typedef struct {
    size_t size;
    int **matrix;
} Matrix;

typedef struct {
    _Atomic int main_diagonal;
    _Atomic int side_diagonal;
} Calculation_res;

int get_main_diagonal(Calculation_res* res);

int get_side_diagonal(Calculation_res* res);

Matrix* read_file(const char* file_name);
void free_matrix(Matrix* matrix);

#endif //HW_2_UTILS_H
