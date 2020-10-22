//
// Created by Andrew Kireev on 18.10.2020.
//

#include "one/utils.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

Matrix* input_matrix() {
    int size;

    if (scanf("%d", &size) != 1)
        return NULL;

    int *data = (int*)malloc(sizeof(int) * size * size);

    int k = 0;
    for (int i = 0; i != size; ++i) {
        for (int j = 0; j != size; ++j) {
            if (scanf("%d", &data[k]) != 1) {
                free(data);
                return NULL;
            }
            ++k;
        }
    }
    Matrix *matrix = (Matrix*)malloc(sizeof(Matrix) * 1);
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

    if (!(matrix->data = (int*)malloc(sizeof(int) * matrix->size * matrix->size))) {
        free(matrix);
        fclose(file);
        return NULL;
    }

    int n = matrix->size;
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != n; ++j) {
            if (fscanf(file, "%d", &matrix->data[i*n+j]) != 1) {
                free(matrix->data);
                free(matrix);
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);
    return matrix;
}

