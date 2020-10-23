//
// Created by Andrew Kireev on 18.10.2020.
//

#include "utils.h"


Calculation_res calculate_matrix(Matrix* matrix) {
    Calculation_res res;
    int n = matrix->size;

    res.main_diagonal = 0;
    res.side_diagonal = 0;

    for (int i = 0; i != n; ++i) {
        res.main_diagonal += matrix->main_diagonal[i];
        res.side_diagonal += matrix->side_diagonal[i];
    }

    return res;
}
