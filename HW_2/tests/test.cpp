//
// Created by Andrew Kireev on 21.10.2020.
//

#include <gtest/gtest.h>
#include <string>
#include <sys/mman.h>


extern "C" {

    #include "one/one_proc_utils.h"
    #include "multi/multi_process_utils.h"
}

TEST(read_file, reading_from_file_test2) {
    Matrix* matrix = read_file(SOURCE_DIR"/tests/tes");
    if (matrix != NULL)
        free_matrix(matrix);
}

// Тест синхронного алгоритма

TEST(calculate_matrix, calculate_matrix_one_proc) {
    Matrix* matrix = read_file(SOURCE_DIR"/tests/test1");

    if (matrix != NULL) {
        Calculation_res res = calculate_matrix(matrix);

        free_matrix(matrix);
        EXPECT_EQ(15, res.main_diagonal);
        EXPECT_EQ(16, res.side_diagonal);
    }
}

////Теста синхронного функции calculate_matrix_one_proc, которая читает и вычисляет матрицу

TEST(calculate_matrix_one_proc, test_synchronous_calc) {
    char file_name[] = SOURCE_DIR"/tests/test1";
    Calculation_res res = calculate_matrix_one_proc(file_name);

    EXPECT_EQ(15, res.main_diagonal);
    EXPECT_EQ(16, res.side_diagonal);
}

// Тест чтения из файлов

TEST(read_file, reading_from_file_test1) {

    Matrix* matrix = read_file(SOURCE_DIR"/tests/test1");

    if (matrix != NULL) {
        Calculation_res res = calculate_matrix(matrix);
        free_matrix(matrix);

        EXPECT_EQ(15, res.main_diagonal);
        EXPECT_EQ(16, res.side_diagonal);
    }
}

TEST(read_file, reading_from_file_test3) {


    Matrix* matrix = read_file(SOURCE_DIR"/tests/test2");

    if (matrix != NULL) {

        Calculation_res res = calculate_matrix(matrix);
        free_matrix(matrix);

        EXPECT_EQ(5, res.main_diagonal);
        EXPECT_EQ(5, res.side_diagonal);
    }
}

// Тест многопроцессорного алгоритма

TEST(multi_process, test_1_multi_process) {

    char file_name[] = SOURCE_DIR"/tests/5";

    Calculation_multi_proc_res* res = multi_process(file_name, 5);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        munmap(res, getpagesize());

        EXPECT_EQ(32, main);
        EXPECT_EQ(14, side);
    }
}


TEST(multi_process, test_4_multi_process) {

    char file_name[] = SOURCE_DIR"/tests/7";

    Calculation_multi_proc_res* res = multi_process(file_name, 2);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        munmap(res, getpagesize());
        EXPECT_EQ(24, main);
        EXPECT_EQ(42, side);
    }

    Calculation_multi_proc_res* res2 = multi_process(file_name, 5);

    if (res2 != NULL) {
        int main = res2->main_diagonal;
        int side = res2->side_diagonal;
        munmap(res2, getpagesize());
        EXPECT_EQ(24, main);
        EXPECT_EQ(42, side);
    }

    Calculation_multi_proc_res* res3 = multi_process(file_name, 3);

    if (res3 != NULL) {
        int main = res3->main_diagonal;
        int side = res3->side_diagonal;
        munmap(res3, getpagesize());
        EXPECT_EQ(24,  main);
        EXPECT_EQ(42, side);
    }

    Calculation_multi_proc_res* res4 = multi_process(file_name, 50);

    if (res4 != NULL) {
        int main = res4->main_diagonal;
        int side = res4->side_diagonal;
        munmap(res4, getpagesize());
        EXPECT_EQ(24, main);
        EXPECT_EQ(42, side);
    }
}


// Сравнение результатов синхронного и многопроцессорного алгоритма
// При разных матрицах и разном количестве процессов

TEST(multi_process, compare_algs_matrix_size_10) {

    char file_name[] = SOURCE_DIR"/tests/size_10";

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

TEST(multi_process, compare_algs_matrix_size_23) {

    char file_name[] = SOURCE_DIR"/tests/size_23";

    Calculation_multi_proc_res* res = multi_process(file_name, 4);

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

TEST(multi_process, compare_algs_matrix_size_123) {

    char file_name[] = SOURCE_DIR"/tests/size_123";

    Calculation_multi_proc_res* res = multi_process(file_name, 12);

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

TEST(multi_process, compare_algs_matrix_size_200) {

    char file_name[] = SOURCE_DIR"/tests/size_200";

    Calculation_multi_proc_res* res = multi_process(file_name, 20);

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

TEST(multi_process, compare_algs_matrix_size_555) {

    char file_name[] = SOURCE_DIR"/tests/size_555";

    Calculation_multi_proc_res* res = multi_process(file_name, 11);

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

TEST(multi_process, compare_algs_matrix_size_666) {

    char file_name[] = SOURCE_DIR"/tests/size_666";

    Calculation_multi_proc_res* res = multi_process(file_name, 23);

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

TEST(multi_process, compare_algs_matrix_size_1333) {

    char file_name[] = SOURCE_DIR"/tests/size_1333";

    Calculation_multi_proc_res* res = multi_process(file_name, 50);

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

TEST(multi_process, compare_algs_matrix_size_1777) {

    char file_name[] = SOURCE_DIR"/tests/size_1777";

    Calculation_multi_proc_res* res = multi_process(file_name, 100);

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

TEST(multi_process, compare_algs_matrix_size_5000) {

    char file_name[] = SOURCE_DIR"/tests/size_5000";

    Calculation_multi_proc_res* res = multi_process(file_name, 10);

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

TEST(multi_process, compare_algs_matrix_size_10000) {

    char file_name[] = SOURCE_DIR"/tests/size_10000";

    Calculation_multi_proc_res* res = multi_process(file_name, 30);

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

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}