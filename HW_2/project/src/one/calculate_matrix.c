//
// Created by Andrew Kireev on 18.10.2020.
//

#include "one/utils.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

Calculation_res calculate_matrix(Matrix* matrix) {
    Calculation_res res;
    int n = matrix->size;

    res.main_diagonal = 0;
    res.side_diagonal = 0;

    for (int i = 0; i != n; ++i) {
        res.main_diagonal += matrix->main_diagonal[i];
        res.side_diagonal += matrix->side_diagonal[i];
    }

//    free(matrix->main_diagonal);
//    free(matrix->side_diagonal);
//    free(matrix);
    return res;
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

    if (!(matrix->main_diagonal = (int*)malloc(sizeof(int) * matrix->size))) {
        free(matrix);
        fclose(file);
        return NULL;
    }

    if (!(matrix->side_diagonal = (int*)malloc(sizeof(int) * matrix->size))) {
        free(matrix->main_diagonal);
        free(matrix);
        fclose(file);
        return NULL;
    }

    int *tmp_one_row;
    if (!(tmp_one_row = (int*)malloc(sizeof(int) * matrix->size))) {
        free(matrix->main_diagonal);
        free(matrix->side_diagonal);
        free(matrix);
        fclose(file);
        return NULL;
    }

    int n = matrix->size;
    int k_main = 0;
    int k_side = 0;
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != n; ++j) {
            if (fscanf(file, "%d", &tmp_one_row[j]) != 1) {
                free(tmp_one_row);
                free(matrix->main_diagonal);
                free(matrix->side_diagonal);
                free(matrix);
                fclose(file);
                return NULL;
            }
        }
        matrix->main_diagonal[k_main++] = tmp_one_row[i];
        matrix->side_diagonal[k_side++] = tmp_one_row[n - i - 1];
    }

    free(tmp_one_row);
    fclose(file);
    return matrix;
}

