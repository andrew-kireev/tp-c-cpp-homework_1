//
// Created by Andrew Kireev on 18.10.2020.
//

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    Calculation_res *res = create_shared_memory();

    create_forks(4);

    printf("Создался поток%c", '\n');

    res->main_diagonal++;
    res->side_diagonal++;


    printf("main_diagonal = %d\n", res->main_diagonal);
    printf("side_diagonal = %d\n", res->side_diagonal);



//    Matrix* matrix = input_matrix();
//
//    print_matrix(matrix);
//
//    Calculation_res res = calculate_matrix(matrix);
//    printf("%d\n", res.main_diagonal);
//    printf("%d\n", res.side_diagonal);
//
//    free(matrix->data);
//    free(matrix);
    return 0;
}
