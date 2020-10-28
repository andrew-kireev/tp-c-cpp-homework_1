//
// Created by Andrew Kireev on 22.10.2020.
//


#include <gtest/gtest.h>
#include <string>
#include <sys/mman.h>


extern "C" {
#include "one/one_proc_utils.h"
#include "multi/multi_process_utils.h"
}

// Сравнение результатов синхронного и многопроцессорного алгоритма
// При разных матрицах и разном количестве процессов

TEST(multi_process, compare_algs_matrix_size_10) {

    char file_name[] = SOURCE_DIR"/tests/size_10";

    Matrix *matrix = read_file(file_name);

    if (matrix == NULL) {
        return;
    }
    Calculation_res* res = multi_process(matrix);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        free(res);


        Calculation_res* res2 = calculate_matrix(matrix);
        free_matrix(matrix);
        int main2 = res2->main_diagonal;
        int side2 = res2->side_diagonal;
        free(res2);

        EXPECT_EQ(main2, main);
        EXPECT_EQ(side2, side);
    } else
        free_matrix(matrix);
}

TEST(multi_process, compare_algs_matrix_size_20) {

    char file_name[] = SOURCE_DIR"/tests/size_20";

    Matrix *matrix = read_file(file_name);

    if (matrix == NULL) {
        return;
    }
    Calculation_res* res = multi_process(matrix);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        free(res);


        Calculation_res* res2 = calculate_matrix(matrix);
        free_matrix(matrix);
        int main2 = res2->main_diagonal;
        int side2 = res2->side_diagonal;
        free(res2);

        EXPECT_EQ(main2, main);
        EXPECT_EQ(side2, side);
    } else
        free_matrix(matrix);
}

TEST(multi_process, compare_algs_matrix_size_30) {

    char file_name[] = SOURCE_DIR"/tests/size_30";

    Matrix *matrix = read_file(file_name);

    if (matrix == NULL) {
        return;
    }
    Calculation_res* res = multi_process(matrix);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        free(res);


        Calculation_res* res2 = calculate_matrix(matrix);
        free_matrix(matrix);
        int main2 = res2->main_diagonal;
        int side2 = res2->side_diagonal;
        free(res2);

        EXPECT_EQ(main2, main);
        EXPECT_EQ(side2, side);
    } else
        free_matrix(matrix);
}

TEST(multi_process, compare_algs_matrix_size_40) {

    char file_name[] = SOURCE_DIR"/tests/size_40";

    Matrix *matrix = read_file(file_name);

    if (matrix == NULL) {
        return;
    }
    Calculation_res* res = multi_process(matrix);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        free(res);


        Calculation_res* res2 = calculate_matrix(matrix);
        free_matrix(matrix);
        int main2 = res2->main_diagonal;
        int side2 = res2->side_diagonal;
        free(res2);

        EXPECT_EQ(main2, main);
        EXPECT_EQ(side2, side);
    } else
        free_matrix(matrix);
}

TEST(multi_process, compare_algs_matrix_size_50) {

    char file_name[] = SOURCE_DIR"/tests/size_50";

    Matrix *matrix = read_file(file_name);

    if (matrix == NULL) {
        return;
    }
    Calculation_res* res = multi_process(matrix);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        free(res);


        Calculation_res* res2 = calculate_matrix(matrix);
        free_matrix(matrix);
        int main2 = res2->main_diagonal;
        int side2 = res2->side_diagonal;
        free(res2);

        EXPECT_EQ(main2, main);
        EXPECT_EQ(side2, side);
    } else
        free_matrix(matrix);
}

TEST(multi_process, compare_algs_matrix_size_60) {

    char file_name[] = SOURCE_DIR"/tests/size_60";

    Matrix *matrix = read_file(file_name);

    if (matrix == NULL) {
        return;
    }
    Calculation_res* res = multi_process(matrix);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        free(res);


        Calculation_res* res2 = calculate_matrix(matrix);
        free_matrix(matrix);
        int main2 = res2->main_diagonal;
        int side2 = res2->side_diagonal;
        free(res2);

        EXPECT_EQ(main2, main);
        EXPECT_EQ(side2, side);
    } else
        free_matrix(matrix);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}