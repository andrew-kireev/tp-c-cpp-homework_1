//
// Created by Andrew Kireev on 07.10.2020.
//
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "road_information.h"
}

TEST(evaluate_road_quality, quality_test1) {


    ASSERT_EQ(80, evaluate_road_quality(EXCELLENT));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}