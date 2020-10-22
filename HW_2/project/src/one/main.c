//
// Created by Andrew Kireev on 21.10.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "one/utils.h"



int main(int argc, char **argv) {
    Matrix* matrix = read_file("/Users/andrewkireev/Documents/GitHub/tp-c-cpp-homework_1/HW_2/tests/7");

    for (int i = 0; i != matrix->size; ++i)
        printf("%d ", matrix->main_diagonal[i]);
    printf("%c", '\n');

    for (int i = 0; i != matrix->size; ++i)
        printf("%d ", matrix->side_diagonal[i]);
    printf("%c", '\n');

    Calculation_res res = calculate_matrix(matrix);

    printf("res_main = %d\n", res.main_diagonal);
    printf("res_side = %d\n", res.side_diagonal);

    return 0;
}
