//
// Created by Andrew Kireev on 21.10.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "one/utils.h"

int main(int argc, char **argv) {

    Matrix* matrix = input_matrix();

    print_matrix(matrix);

    Calculation_res res = calculate_matrix(matrix);
    printf("%d\n", res.main_diagonal);
    printf("%d\n", res.side_diagonal);

    free(matrix->data);
    free(matrix);
    return 0;
}
