//
// Created by Andrew Kireev on 07.10.2020.
//
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "road_information.h"
}

//evaluate_road_quality

TEST(evaluate_road_quality, evaluate_road_quality_test1) {
    ASSERT_EQ(80, evaluate_road_quality(EXCELLENT));
}

TEST(evaluate_road_quality, evaluate_road_quality_test2) {
    ASSERT_EQ(60, evaluate_road_quality(GOOD));
}

//evaluate_road_surface

TEST(evaluate_road_surface, evaluate_road_surface_test1) {
    ASSERT_EQ(15, evaluate_road_surface(CONCRETE));
}

TEST(evaluate_road_surface, evaluate_road_surface_test2) {
    ASSERT_EQ(-35, evaluate_road_surface(CRUSHED_STONE));
}

//evaluate_road_len

TEST(evaluate_road_len, evaluate_road_len_test1) {
    ASSERT_EQ(20, evaluate_road_len(300));
}

TEST(evaluate_road_len, evaluate_road_len_test2) {
    ASSERT_EQ(10, evaluate_road_len(110));
}

TEST(evaluate_road_len, evaluate_road_len_test3) {
    ASSERT_EQ(-10, evaluate_road_len(10));
}

//evaluate_amount_lines

TEST(evaluate_amount_lines, evaluate_amount_lines_test1) {
    ASSERT_EQ(5, evaluate_amount_lines(3));
}

TEST(evaluate_amount_lines, evaluate_amount_lines_test2) {
    ASSERT_EQ(-5, evaluate_amount_lines(1));
}

//final_quality

TEST(final_quality, final_quality_test1) {
    ASSERT_EQ(EXCELLENT, final_quality(81));
}

TEST(final_quality, final_quality_test2) {
    ASSERT_EQ(TERRIBLE, final_quality(20));
}


TEST(final_quality, final_quality_test3) {
    ASSERT_EQ(TERRIBLE, final_quality(-20));
}

//rate_road

TEST(rate_road, rate_road_test1) {
    Road_Information road;

    road.quality = GOOD;
    road.surface = SAND;
    road.road_len = 110;
    road.road_lines_num = 1;

    ASSERT_EQ(45, rate_road(road));

    Road_Information road1;

    road1.quality = TERRIBLE;
    road1.surface = CONCRETE;
    road1.road_len = 500;
    road1.road_lines_num = 5;

    ASSERT_EQ(45, rate_road(road1));

    Road_Information road2;

    road2.quality = NORMAL;
    road2.surface = CRUSHED_STONE;
    road2.road_len = 500;
    road2.road_lines_num = 8;

    ASSERT_EQ(35, rate_road(road2));

    Road_Information road3;

    road3.quality = BAD;
    road3.surface = CRUSHED_STONE;
    road3.road_len = 100;
    road3.road_lines_num = 2;

    ASSERT_EQ(-5, rate_road(road3));
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}