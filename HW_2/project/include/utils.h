//
// Created by Andrew Kireev on 23.10.2020.
//

#ifndef HW_2_UTILS_H
#define HW_2_UTILS_H

#include <stdlib.h>

typedef struct {
    size_t size;
    int **matrix;
} Matrix;

typedef struct {
    int main_diagonal;
    int side_diagonal;
} Calculation_res;

Matrix* read_file(const char* file_name);

#endif //HW_2_UTILS_H
