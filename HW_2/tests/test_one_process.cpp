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

TEST(read_file, read) {
    Matrix* matrix = read_file(SOURCE_DIR"/tests/tes");
    if (matrix != NULL)
        free_matrix(matrix);
}

//
//
TEST(calculate_matrix, test1_calculate_matrix) {
    Matrix* matrix = read_file(SOURCE_DIR"/tests/test1");

    if (matrix != NULL) {
        Calculation_res res = calculate_matrix(matrix);

        free_matrix(matrix);
        EXPECT_EQ(15, res.main_diagonal);
        EXPECT_EQ(16, res.side_diagonal);
    }
}
//
//
//
TEST(read_file, test1_read_file) {

    Matrix* matrix = read_file(SOURCE_DIR"/tests/test1");

    if (matrix != NULL) {
        Calculation_res res = calculate_matrix(matrix);
        free_matrix(matrix);

        EXPECT_EQ(15, res.main_diagonal);
        EXPECT_EQ(16, res.side_diagonal);
    }
}

TEST(read_file, test2_read_file) {


    Matrix* matrix = read_file(SOURCE_DIR"/tests/test2");

    if (matrix != NULL) {

        Calculation_res res = calculate_matrix(matrix);
        free_matrix(matrix);

        EXPECT_EQ(5, res.main_diagonal);
        EXPECT_EQ(5, res.side_diagonal);
    }
}


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
        munmap(res, getpagesize());
        EXPECT_EQ(24, main);
        EXPECT_EQ(42, side);
    }

    Calculation_multi_proc_res* res3 = multi_process(file_name, 3);

    if (res3 != NULL) {
        int main = res3->main_diagonal;
        int side = res3->side_diagonal;
        munmap(res, getpagesize());
        EXPECT_EQ(24,  main);
        EXPECT_EQ(42, side);
    }

    Calculation_multi_proc_res* res4 = multi_process(file_name, 50);

    if (res4 != NULL) {
        int main = res4->main_diagonal;
        int side = res4->side_diagonal;
        munmap(res, getpagesize());
        EXPECT_EQ(24, main);
        EXPECT_EQ(42, side);
    }
}


TEST(multi_process, compare) {

    char file_name[] = SOURCE_DIR"/tests/size_10";

    Calculation_multi_proc_res* res = multi_process(file_name, 5);

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

TEST(multi_process, compare2) {

    char file_name[] = SOURCE_DIR"/tests/size_23";

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

TEST(multi_process, compare3) {

    char file_name[] = SOURCE_DIR"/tests/size_123";

    Calculation_multi_proc_res* res = multi_process(file_name, 12);

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

TEST(multi_process, compare4) {

    char file_name[] = SOURCE_DIR"/tests/size_200";

    Calculation_multi_proc_res* res = multi_process(file_name, 20);

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

TEST(multi_process, compare5) {

    char file_name[] = SOURCE_DIR"/tests/size_555";

    Calculation_multi_proc_res* res = multi_process(file_name, 11);

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

TEST(multi_process, compare6) {

    char file_name[] = SOURCE_DIR"/tests/size_666";

    Calculation_multi_proc_res* res = multi_process(file_name, 23);

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

TEST(multi_process, compare7) {

    char file_name[] = SOURCE_DIR"/tests/size_1333";

    Calculation_multi_proc_res* res = multi_process(file_name, 50);

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

TEST(multi_process, compare8) {

    char file_name[] = SOURCE_DIR"/tests/size_1777";

    Calculation_multi_proc_res* res = multi_process(file_name, 100);

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

TEST(multi_process, compare9) {

    char file_name[] = SOURCE_DIR"/tests/size_5000";

    Calculation_multi_proc_res* res = multi_process(file_name, 10);

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

TEST(multi_process, compare10) {

    char file_name[] = SOURCE_DIR"/tests/size_10000";

    Calculation_multi_proc_res* res = multi_process(file_name, 30);

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

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}