//
// Created by Andrew Kireev on 21.10.2020.
//

#include <gtest/gtest.h>
#include <string>
#include <sys/mman.h>

extern "C" {
    #include "multi/multi_process_utils.h"
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