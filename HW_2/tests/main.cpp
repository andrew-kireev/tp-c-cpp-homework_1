//
// Created by Andrew Kireev on 18.10.2020.
//

#include <gtest/gtest.h>
#include <string>

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

TEST(read_file, test1_read_file) {

    std::vector<int> test = {4, 5, 4, 3,
                             6, 3, 5, 3,
                             5, 3, 5, 2,
                             5, 3, 5, 3};

    Matrix* matrix = read_file(SOURCE_DIR"/tests/test1");
    bool is_equal = true;
    int size = matrix->size;
    int k = 0;
    for (int i = 0; i != size; ++i) {
        for (int j = 0; j != size; ++j) {
            if (test[k] != matrix->data[i*size+j]) {
                is_equal = false;
                break;
            }
            k++;
        }
    }

    EXPECT_EQ(true, is_equal);

}

TEST(read_file, test2_read_file) {

    std::vector<int> test = {1, 2,
                             3, 4};

    Matrix* matrix = read_file(SOURCE_DIR"/tests/test2");
    bool is_equal = true;
    int size = matrix->size;
    int k = 0;
    for (int i = 0; i != size; ++i) {
        for (int j = 0; j != size; ++j) {
            if (test[k] != matrix->data[i*size+j]) {
                is_equal = false;
                break;
            }
            k++;
        }
    }

    EXPECT_EQ(true, is_equal);

}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}