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

    Calculation_multi_proc_res* res = multi_process(file_name, 2);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        munmap(res, getpagesize());

        Matrix *matrix = read_file(file_name);

        if (matrix == NULL) {
            return;
        }

        Calculation_res res2 = calculate_matrix(matrix);
        free_matrix(matrix);

        EXPECT_EQ(res2.main_diagonal, main);
        EXPECT_EQ(res2.side_diagonal, side);
    }
}

TEST(multi_process, compare_algs_matrix_size_20) {
    char file_name[] = SOURCE_DIR"/tests/size_20";

    Calculation_multi_proc_res* res = multi_process(file_name, 4);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        munmap(res, getpagesize());

        Matrix *matrix = read_file(file_name);

        if (matrix == NULL) {
            munmap(res, getpagesize());
            return;
        }

        Calculation_res res2 = calculate_matrix(matrix);
        free_matrix(matrix);

        EXPECT_EQ(res2.main_diagonal, main);
        EXPECT_EQ(res2.side_diagonal, side);
    }
}

TEST(multi_process, compare_algs_matrix_size_30) {
    char file_name[] = SOURCE_DIR"/tests/size_30";

    Calculation_multi_proc_res* res = multi_process(file_name, 5);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        munmap(res, getpagesize());

        Matrix *matrix = read_file(file_name);

        if (matrix == NULL) {
            return;
        }

        Calculation_res res2 = calculate_matrix(matrix);
        free_matrix(matrix);

        EXPECT_EQ(res2.main_diagonal, main);
        EXPECT_EQ(res2.side_diagonal, side);
    }
}

TEST(multi_process, compare_algs_matrix_size_40) {
    char file_name[] = SOURCE_DIR"/tests/size_40";

    Calculation_multi_proc_res* res = multi_process(file_name, 5);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        munmap(res, getpagesize());

        Matrix *matrix = read_file(file_name);

        if (matrix == NULL) {
            return;
        }

        Calculation_res res2 = calculate_matrix(matrix);
        free_matrix(matrix);

        EXPECT_EQ(res2.main_diagonal, main);
        EXPECT_EQ(res2.side_diagonal, side);
    }
}

TEST(multi_process, compare_algs_matrix_size_50) {
    char file_name[] = SOURCE_DIR"/tests/size_50";

    Calculation_multi_proc_res* res = multi_process(file_name, 7);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        munmap(res, getpagesize());

        Matrix *matrix = read_file(file_name);

        if (matrix == NULL) {
            return;
        }

        Calculation_res res2 = calculate_matrix(matrix);
        free_matrix(matrix);

        EXPECT_EQ(res2.main_diagonal, main);
        EXPECT_EQ(res2.side_diagonal, side);
    }
}

TEST(multi_process, compare_algs_matrix_size_60) {
    char file_name[] = SOURCE_DIR"/tests/size_60";

    Calculation_multi_proc_res* res = multi_process(file_name, 5);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        munmap(res, sizeof(res));

        Matrix *matrix = read_file(file_name);

        if (matrix == NULL) {
            return;
        }

        Calculation_res res2 = calculate_matrix(matrix);
        free_matrix(matrix);

        EXPECT_EQ(res2.main_diagonal, main);
        EXPECT_EQ(res2.side_diagonal, side);
    }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}