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
//


// Тест чтения из файлов

TEST(read_file, reading_from_file_test3) {


    Matrix* matrix = read_file(SOURCE_DIR"/tests/test2");

    if (matrix != NULL) {

        Calculation_res* res = calculate_matrix(matrix);
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        free(res);

        EXPECT_EQ(5, main);
        EXPECT_EQ(5, side);
    }
}

//// Тест синхронного алгоритма

TEST(calculate_matrix, calculate_matrix_one_proc2) {
    Matrix* matrix = read_file(SOURCE_DIR"/tests/test1");

    if (matrix != NULL) {
        Calculation_res* res = calculate_matrix(matrix);
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        free(res);

        free_matrix(matrix);
        EXPECT_EQ(15, main);
        EXPECT_EQ(16, side);
    }
}


TEST(calculate_matrix, calculate_matrix_one_proc) {

    Matrix* matrix = read_file(SOURCE_DIR"/tests/test1");

    if (matrix != NULL) {
        Calculation_res* res = calculate_matrix(matrix);
        free_matrix(matrix);
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        free(res);

        EXPECT_EQ(15, main);
        EXPECT_EQ(16, side);
    }
}

// Тест многопроцессорного алгоритма

TEST(multi_process, test_1_multi_process) {

    char file_name[] = SOURCE_DIR"/tests/5";

    Matrix *matrix = read_file(file_name);

    if (matrix == NULL) {
        return;
    }
    Calculation_res* res = multi_process(matrix);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        free(res);

        EXPECT_EQ(32, main);
        EXPECT_EQ(14, side);
    }
}


TEST(multi_process, test_4_multi_process) {

    char file_name[] = SOURCE_DIR"/tests/7";

    Matrix *matrix = read_file(file_name);

    if (matrix == NULL) {
        return;
    }
    Calculation_res* res = multi_process(matrix);

    if (res != NULL) {
        int main = res->main_diagonal;
        int side = res->side_diagonal;
        free(res);
        EXPECT_EQ(24, main);
        EXPECT_EQ(42, side);
    }
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

TEST(multi_process, compare_algs_matrix_size_23) {

    char file_name[] = SOURCE_DIR"/tests/size_23";

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

TEST(multi_process, compare_algs_matrix_size_123) {

    char file_name[] = SOURCE_DIR"/tests/size_123";

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

TEST(multi_process, compare_algs_matrix_size_200) {

    char file_name[] = SOURCE_DIR"/tests/size_200";

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

TEST(multi_process, compare_algs_matrix_size_555) {

    char file_name[] = SOURCE_DIR"/tests/size_555";

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

TEST(multi_process, compare_algs_matrix_size_666) {

    char file_name[] = SOURCE_DIR"/tests/size_666";

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

TEST(multi_process, compare_algs_matrix_size_1333) {

    char file_name[] = SOURCE_DIR"/tests/size_1333";

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

TEST(multi_process, compare_algs_matrix_size_1777) {

    char file_name[] = SOURCE_DIR"/tests/size_1777";

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

TEST(multi_process, compare_algs_matrix_size_5000) {

    char file_name[] = SOURCE_DIR"/tests/size_5000";

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

TEST(multi_process, compare_algs_matrix_size_10000) {

    char file_name[] = SOURCE_DIR"/tests/size_10000";

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