//
// Created by Andrew Kireev on 18.10.2020.
//

#include "utils.h"
#include <stdlib.h>

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

Matrix* read_file(char* file) {
    int fd = open
}
