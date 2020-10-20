//
// Created by Andrew Kireev on 18.10.2020.
//

#include <gtest/gtest.h>
#include <string>
#include <sys/mman.h>

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


    Calculation_res res = calculate_matrix(matrix);
    EXPECT_EQ(15, res.main_diagonal);
    EXPECT_EQ(16, res.side_diagonal);

    free(matrix->data);
    free(matrix);
}

TEST(read_file, test2_read_file) {

    std::vector<int> test = {1, 2,
                             3, 4};

    Matrix* matrix = read_file("/Users/andrewkireev/Documents/GitHub/tp-c-cpp-homework_1/HW_2/tests/test2");
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

    Calculation_res res = calculate_matrix(matrix);
    EXPECT_EQ(5, res.main_diagonal);
    EXPECT_EQ(5, res.side_diagonal);
    free(matrix->data);
    free(matrix);
}


TEST(multi_process, test_1_multi_process) {

    char file_name[] = "/Users/andrewkireev/Documents/GitHub/tp-c-cpp-homework_1/HW_2/tests/5";

    Calculation_res* res = multi_process(file_name, 5);

    EXPECT_EQ(32, res->main_diagonal);
    EXPECT_EQ(14, res->side_diagonal);
    munmap(res, getpagesize());
}

TEST(multi_process, test_4_multi_process) {

    char file_name[] = "/Users/andrewkireev/Documents/GitHub/tp-c-cpp-homework_1/HW_2/tests/7";

    Calculation_res* res = multi_process(file_name, 2);

    EXPECT_EQ(24, res->main_diagonal);
    EXPECT_EQ(42, res->side_diagonal);
    munmap(res, getpagesize());

    Calculation_res* res2 = multi_process(file_name, 2);

    EXPECT_EQ(24, res2->main_diagonal);
    EXPECT_EQ(42, res2->side_diagonal);
    munmap(res2, getpagesize());

    Calculation_res* res3 = multi_process(file_name, 3);

    EXPECT_EQ(24, res3->main_diagonal);
    EXPECT_EQ(42, res3->side_diagonal);
    munmap(res3, getpagesize());

    Calculation_res* res4 = multi_process(file_name, 50);

    EXPECT_EQ(24, res4->main_diagonal);
    EXPECT_EQ(42, res4->side_diagonal);
    munmap(res3, getpagesize());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}