//
// Created by Andrew Kireev on 18.10.2020.
//

#include <gtest/gtest.h>

extern "C" {
    #include "utils.h"
}


TEST(calculate_matrix, test1_calculate_matrix) {
    int mas[] = {5, 3, 4,
                 2, 4, 2,
                 2, 4, 6};

    Matrix matrix;
    matrix.size = 3;
    matrix.data = mas;

    EXPECT_EQ(15, calculate_matrix(&matrix).main_diagonal);
    EXPECT_EQ(10, calculate_matrix(&matrix).side_diagonal);
}

TEST(calculate_matrix, test2_calculate_matrix) {
    int mas[] = {0, 0, 1,
                 0, 0, 0,
                 0, 0, 0};

    Matrix matrix;
    matrix.size = 3;
    matrix.data = mas;

    EXPECT_EQ(0, calculate_matrix(&matrix).main_diagonal);
    EXPECT_EQ(1, calculate_matrix(&matrix).side_diagonal);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}