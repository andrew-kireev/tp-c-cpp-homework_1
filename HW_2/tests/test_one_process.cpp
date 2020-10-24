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



//
//TEST(calculate_matrix, test1_calculate_matrix) {
//    int mas1[] = {5, 4, 6};
//
//    int mas2[] = {4, 4, 2};
//
//    Matrix matrix;
//    matrix.size = 3;
//    matrix.main_diagonal = mas1;
//    matrix.side_diagonal = mas2;
//
//    EXPECT_EQ(15, calculate_matrix(&matrix).main_diagonal);
//    EXPECT_EQ(10, calculate_matrix(&matrix).side_diagonal);
//
//}
//
//TEST(calculate_matrix, test2_calculate_matrix) {
//    int mas1[] = {0, 0, 0};
//
//    int mas2[] = {1, 0, 0};
//
//    Matrix matrix;
//    matrix.size = 3;
//    matrix.main_diagonal = mas1;
//    matrix.side_diagonal = mas2;
//
//    EXPECT_EQ(0, calculate_matrix(&matrix).main_diagonal);
//    EXPECT_EQ(1, calculate_matrix(&matrix).side_diagonal);
//}

//TEST(read_file, test1_read_file) {
//
//    std::vector<int> main = {4, 3, 5, 2};
//
//    std::vector<int> side = {3, 5, 3, 5};
//
//    Matrix* matrix = read_file(SOURCE_DIR"/tests/test1");
//    bool is_equal = true;
//    int size = matrix->size;
//    for (int i = 0; i != size; ++i) {
//        if (main[i] != matrix->main_diagonal[i] || side[i] != matrix->side_diagonal[i]) {
//            is_equal = false;
//            break;
//        }
//    }
//
//    EXPECT_EQ(true, is_equal);
//
//
//    Calculation_res res = calculate_matrix(matrix);
//    EXPECT_EQ(15, res.main_diagonal);
//    EXPECT_EQ(16, res.side_diagonal);
//
//    free(matrix->main_diagonal);
//    free(matrix->side_diagonal);
//    free(matrix);
//}
//
//TEST(read_file, test2_read_file) {
//
//    std::vector<int> test = {1, 2,
//                             3, 4};
//
//    Matrix* matrix = read_file(SOURCE_DIR"/tests/test2");
//    bool is_equal = true;
//    int size = matrix->size;
//    int k = 0;
//    for (int i = 0; i != size; ++i) {
//        for (int j = 0; j != size; ++j) {
//            if (test[k] != matrix->data[i*size+j]) {
//                is_equal = false;
//                break;
//            }
//            k++;
//        }
//    }
//
//    EXPECT_EQ(true, is_equal);
//
//    Calculation_res res = calculate_matrix(matrix);
//    EXPECT_EQ(5, res.main_diagonal);
//    EXPECT_EQ(5, res.side_diagonal);
//    free(matrix->side_diagonal);
//    free(matrix->main_diagonal);
//    free(matrix);
//}


//TEST(multi_process, test_1_multi_process) {
//
//    char file_name[] = SOURCE_DIR"/tests/5";
//
//    Calculation_res* res = multi_process(file_name, 5);
//
//    EXPECT_EQ(32, get_main_diagonal(res));
//    EXPECT_EQ(14, get_side_diagonal(res));
//    free(res);
//}
//
//TEST(multi_process, test_4_multi_process) {
//
//    char file_name[] = SOURCE_DIR"/tests/7";
//
//    Calculation_res* res = multi_process(file_name, 2);
//
//    EXPECT_EQ(24, get_main_diagonal(res));
//    EXPECT_EQ(42, get_side_diagonal(res));
//    free(res);
//
//    Calculation_res* res2 = multi_process(file_name, 2);
//
//    EXPECT_EQ(24, get_main_diagonal(res2));
//    EXPECT_EQ(42, get_side_diagonal(res2));
//    free(res2);
//
//    Calculation_res* res3 = multi_process(file_name, 3);
//
//    EXPECT_EQ(24, get_main_diagonal(res3));
//    EXPECT_EQ(42, get_side_diagonal(res3));
//    free(res3);
//
//    Calculation_res* res4 = multi_process(file_name, 50);
//
//    EXPECT_EQ(24, get_main_diagonal(res4));
//    EXPECT_EQ(42, get_side_diagonal(res4));
//    free(res4);
//}


TEST(multi_process, compare) {

    char file_name[] = SOURCE_DIR"/tests/size_10";

    Calculation_res* res = multi_process(file_name, 5);

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

TEST(multi_process, compare2) {

    char file_name[] = SOURCE_DIR"/tests/size_23";

    Calculation_res* res = multi_process(file_name, 4);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_23");

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

    char file_name[] = SOURCE_DIR"/tests/size_123";

    Calculation_res* res = multi_process(file_name, 12);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_123");

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

    char file_name[] = SOURCE_DIR"/tests/size_200";

    Calculation_res* res = multi_process(file_name, 20);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_200");

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

    char file_name[] = SOURCE_DIR"/tests/size_555";

    Calculation_res* res = multi_process(file_name, 11);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_555");

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

    char file_name[] = SOURCE_DIR"/tests/size_666";

    Calculation_res* res = multi_process(file_name, 23);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_666");

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

TEST(multi_process, compare7) {

    char file_name[] = SOURCE_DIR"/tests/size_1333";

    Calculation_res* res = multi_process(file_name, 50);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_1333");

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

TEST(multi_process, compare8) {

    char file_name[] = SOURCE_DIR"/tests/size_1777";

    Calculation_res* res = multi_process(file_name, 100);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_1777");

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

TEST(multi_process, compare9) {

    char file_name[] = SOURCE_DIR"/tests/size_5000";

    Calculation_res* res = multi_process(file_name, 50);

    Matrix* matrix = read_file(SOURCE_DIR"/tests/size_5000");

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


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}