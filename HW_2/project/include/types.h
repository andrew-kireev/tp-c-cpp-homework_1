//
// Created by Andrew Kireev on 21.10.2020.
//

#ifndef HW_2_TYPES_H
#define HW_2_TYPES_H

typedef struct {
    size_t size;
    int *data;
} Matrix;

typedef struct {
    int main_diagonal;
    int side_diagonal;
} Calculation_res;

#endif //HW_2_TYPES_H