//
// Created by Andrew Kireev on 21.10.2020.
//

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include "one/one_proc_utils.h"
#include "multi/multi_process_utils.h"
#include <pthread.h>



int main(int argc, char **argv) {

    char file_name[50] = {};

    scanf("%s", file_name);

    Matrix* matrix = read_file(file_name);
    if (matrix == NULL)
        return 0;

    Calculation_res one_proc_res = calculate_matrix(matrix);

    printf("Результат вычислений синхронного алгоритма:%c", '\n');
    printf("Сумма главной диагонали = %d\n", one_proc_res.main_diagonal);
    printf("Сумма побочной диагонали = %d\n", one_proc_res.side_diagonal);


    int num_forks = 10;
    scanf("%d", &num_forks);

    Calculation__multi_proc_res* multi_proc_res = multi_process(file_name, num_forks);
    if (multi_proc_res == NULL)
        return 0;

    printf("Результат вычислений много-процессорного алгоритма:%c", '\n');
    printf("Сумма главной диагонали = %d\n", multi_proc_res->main_diagonal);
    printf("Сумма побочной диагонали = %d\n", multi_proc_res->side_diagonal);

    if (multi_proc_res->main_diagonal == one_proc_res.main_diagonal &&
    multi_proc_res->side_diagonal == one_proc_res.side_diagonal)
        printf("Результаты вычислений совпадают%c", '\n');
    else
        printf("Результаты не вычислений совпадают%c", '\n');

    munmap(multi_proc_res, getpagesize());
    return 0;
}
