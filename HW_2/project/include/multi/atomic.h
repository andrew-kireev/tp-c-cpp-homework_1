//
// Created by Andrew Kireev on 24.10.2020.
//

#ifndef HW_2_ATOMIC_H
#define HW_2_ATOMIC_H

#include <stdatomic.h>

typedef struct {
    _Atomic int main_diagonal;
    _Atomic int side_diagonal;
} Calculation_multi_proc_res;

int calculate_multi_proc(Matrix* matrix, Calculation_multi_proc_res* res, int proc_number, int procs_amount);

#endif //HW_2_ATOMIC_H
