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
        for (int j = 0; j != n; ++j) {
            if (i == j)
                res.main_diagonal += matrix->matrix[i][j];
            if (n == i + j + 1)
                res.side_diagonal += matrix->matrix[i][j];
        }
    }

    return res;
}
