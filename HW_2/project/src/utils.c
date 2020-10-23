//
// Created by Andrew Kireev on 23.10.2020.
//

#include "utils.h"
#include <stdio.h>

Matrix* read_file(const char* file_name) {
    FILE* file;

    file = fopen(file_name, "r");
    if (file == NULL)
        return NULL;

    Matrix* matrix;
    if (!(matrix = (Matrix*)malloc(sizeof(Matrix) * 1))) {
        fclose(file);
        return NULL;
    }

    if (fscanf(file, "%zu", &matrix->size) != 1) {
        free(matrix);
        fclose(file);
        return NULL;
    }

    if (!(matrix->matrix = (int**)malloc(sizeof(int*) * matrix->size))) {
        free(matrix);
        fclose(file);
        return NULL;
    }

    for (int i = 0; i != matrix->size; ++i) {
        if (!(matrix->matrix[i] = (int*)malloc(sizeof(int) * matrix->size))) {
            for (int j = 0; j != i; ++j)
                free(matrix->matrix[j]);
            free(matrix->matrix);
            free(matrix);
            fclose(file);
            return NULL;
        }
    }

    int n = matrix->size;
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != n; ++j) {
            if (fscanf(file, "%d", &matrix->matrix[i][j]) != 1) {
                for (int k = 0; k != n; ++k)
                    free(matrix->matrix[k]);
                free(matrix->matrix);
                free(matrix);
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);
    return matrix;
}

void free_matrix(Matrix* matrix) {
    int n = matrix->size;

    for (int i = 0; i != n; ++i)
        free(matrix->matrix[i]);
    free(matrix->matrix);
    free(matrix);
}
