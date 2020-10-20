//
// Created by Andrew Kireev on 18.10.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "multi/multi_process_utils.h"

int main(int argc, char **argv) {

    Calculation_res *res = create_shared_memory();

//    create_forks(4 0);

    printf("Создался поток%c", '\n');

    res->main_diagonal++;
    res->side_diagonal++;


    printf("main_diagonal = %d\n", res->main_diagonal);
    printf("side_diagonal = %d\n", res->side_diagonal);

    return 0;
}
