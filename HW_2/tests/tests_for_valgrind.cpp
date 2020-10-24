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

TEST(multi_process, compare2) {
    char file_name[] = SOURCE_DIR"/tests/size_10";

    Calculation_res* res = multi_process(file_name, 2);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_10");

    if (matrix == NULL) {
        munmap(res, getpagesize());
        return;
    }

    Calculation_res res2 = calculate_matrix(matrix);

    EXPECT_EQ(get_main_diagonal(&res2), get_main_diagonal(res));
    EXPECT_EQ(get_side_diagonal(&res2), get_side_diagonal(res));
    munmap(res, getpagesize());
    free_matrix(matrix);
}

TEST(multi_process, compare3) {
    char file_name[] = SOURCE_DIR"/tests/size_20";

    Calculation_res* res = multi_process(file_name, 4);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_20");

    if (matrix == NULL) {
        munmap(res, getpagesize());
        return;
    }

    Calculation_res res2 = calculate_matrix(matrix);

    EXPECT_EQ(get_main_diagonal(&res2), get_main_diagonal(res));
    EXPECT_EQ(get_side_diagonal(&res2), get_side_diagonal(res));
    munmap(res, getpagesize());
    free_matrix(matrix);
}

TEST(multi_process, compare4) {
    char file_name[] = SOURCE_DIR"/tests/size_30";

    Calculation_res* res = multi_process(file_name, 5);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_30");

    if (matrix == NULL) {
        munmap(res, getpagesize());
        return;
    }

    Calculation_res res2 = calculate_matrix(matrix);

    EXPECT_EQ(get_main_diagonal(&res2), get_main_diagonal(res));
    EXPECT_EQ(get_side_diagonal(&res2), get_side_diagonal(res));
    munmap(res, getpagesize());
    free_matrix(matrix);
}

TEST(multi_process, compare5) {
    char file_name[] = SOURCE_DIR"/tests/size_40";

    Calculation_res* res = multi_process(file_name, 5);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_40");

    if (matrix == NULL) {
        munmap(res, getpagesize());
        return;
    }

    Calculation_res res2 = calculate_matrix(matrix);

    EXPECT_EQ(get_main_diagonal(&res2), get_main_diagonal(res));
    EXPECT_EQ(get_side_diagonal(&res2), get_side_diagonal(res));
    munmap(res, getpagesize());
    free_matrix(matrix);
}

TEST(multi_process, compare6) {
    char file_name[] = SOURCE_DIR"/tests/size_50";

    Calculation_res* res = multi_process(file_name, 7);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_50");

    if (matrix == NULL) {
        munmap(res, getpagesize());
        return;
    }

    Calculation_res res2 = calculate_matrix(matrix);

    EXPECT_EQ(get_main_diagonal(&res2), get_main_diagonal(res));
    EXPECT_EQ(get_side_diagonal(&res2), get_side_diagonal(res));
    munmap(res, getpagesize());
    free_matrix(matrix);
}

//TEST(multi_process, compare7) {
//    char file_name[] = SOURCE_DIR"/tests/size_60";
//
//    Calculation_res* res = multi_process(file_name, 5);
//
//    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_60");
//
//    Calculation_res res2 = calculate_matrix(matrix);
//
//    EXPECT_EQ(res2.main_diagonal, res->main_diagonal);
//    EXPECT_EQ(res2.side_diagonal, res->side_diagonal);
//    munmap(res, getpagesize());
//    free(matrix->side_diagonal);
//    free(matrix->main_diagonal);
//    free(matrix);
//}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}