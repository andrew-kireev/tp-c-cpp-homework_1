//
// Created by Andrew Kireev on 18.10.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "multi/multi_process_utils.h"

int main(int argc, char **argv) {
    Calculation_res *res = multi_process("/Users/andrewkireev/Documents/GitHub/tp-c-cpp-homework_1/HW_2/tests/test2", 2);

    printf("main diagonal = %d\n", res->main_diagonal);
    printf("side diagonal = %d\n", res->side_diagonal);


    return 0;
}
