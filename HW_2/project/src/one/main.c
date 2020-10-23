//
// Created by Andrew Kireev on 21.10.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "one/one_proc_utils.h"



int main(int argc, char **argv) {
    Matrix* matrix = read_file("/Users/andrewkireev/Documents/GitHub/tp-c-cpp-homework_1/HW_2/tests/7");

    for (int i = 0; i != matrix->size; ++i) {
        for (int j = 0; j != matrix->size; ++j) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("%c", '\n');
    }

    Calculation_res res = calculate_matrix(matrix);

    for (int j = 0; j != matrix->size; ++j) {
        free(matrix->matrix[j]);
    }
    free(matrix->matrix);
    free(matrix);

    printf("main = %d\n", res.main_diagonal);
    printf("side = %d\n", res.side_diagonal);


    return 0;
}
