//
// Created by Andrew Kireev on 07.10.2020.
//
#include <gtest/gtest.h>
#include <string>

extern "C" {
    #include "road_information.h"
}

//evaluate_road_quality

//Проверка соответствия качества дороги EXCELLENT рейтингу 80

TEST(evaluate_road_quality, evaluate_road_quality_test1) {
    EXPECT_EQ(80, evaluate_road_quality(EXCELLENT));
}

//Проверка соответствия качества дороги GOOD рейтингу 60

TEST(evaluate_road_quality, evaluate_road_quality_test2) {
    EXPECT_EQ(60, evaluate_road_quality(GOOD));
}

//evaluate_road_surface

//Проверка соответствия полотна дороги CONCRETE рейтингу 15

TEST(evaluate_road_surface, evaluate_road_surface_test1) {
    EXPECT_EQ(15, evaluate_road_surface(CONCRETE));
}

//Проверка соответствия полотна дороги CRUSHED_STONE рейтингу -15

TEST(evaluate_road_surface, evaluate_road_surface_test2) {
    EXPECT_EQ(-35, evaluate_road_surface(CRUSHED_STONE));
}

//evaluate_road_len

//Проверка соответсивя длины дороги 300 рейтингку 20

TEST(evaluate_road_len, evaluate_road_len_test1) {
    EXPECT_EQ(20, evaluate_road_len(300));
}

//Проверка соответсивя длины дороги 110 рейтингку 10

TEST(evaluate_road_len, evaluate_road_len_test2) {
    EXPECT_EQ(10, evaluate_road_len(110));
}

//Проверка соответсивя длины дороги 10 рейтингку -10

TEST(evaluate_road_len, evaluate_road_len_test3) {
    EXPECT_EQ(-10, evaluate_road_len(10));
}

//evaluate_amount_lines

//Проверка соответсивя количества полос 3 рейтину 5

TEST(evaluate_amount_lines, evaluate_amount_lines_test1) {
    EXPECT_EQ(5, evaluate_amount_lines(3));
}

//Проверка соответсивя количества полос 1 рейтину -5

TEST(evaluate_amount_lines, evaluate_amount_lines_test2) {
    EXPECT_EQ(-5, evaluate_amount_lines(1));
}

//final_quality

//Проверка соответсвия рейтинга 81 качеству EXCELLENT

TEST(final_quality, final_quality_test1) {
    EXPECT_EQ(EXCELLENT, final_quality(81));
}

//Проверка соответсвия рейтинга 20 качеству TERRIBLE

TEST(final_quality, final_quality_test2) {
    EXPECT_EQ(TERRIBLE, final_quality(20));
}

//Проверка соответсвия рейтинга -20 качеству TERRIBLE

TEST(final_quality, final_quality_test3) {
    EXPECT_EQ(TERRIBLE, final_quality(-20));
}

//rate_road

//Тест оценки дорог с различными параметрами

TEST(rate_road, rate_road_test1) {
    Road_Information road;

    road.quality = GOOD;
    road.surface = SAND;
    road.road_len = 110;
    road.road_lines_num = 1;

    EXPECT_EQ(45, rate_road(road));

    Road_Information road1;

    road1.quality = TERRIBLE;
    road1.surface = CONCRETE;
    road1.road_len = 500;
    road1.road_lines_num = 5;

    EXPECT_EQ(45, rate_road(road1));

    Road_Information road2;

    road2.quality = NORMAL;
    road2.surface = CRUSHED_STONE;
    road2.road_len = 500;
    road2.road_lines_num = 8;

    EXPECT_EQ(35, rate_road(road2));

    Road_Information road3;

    road3.quality = BAD;
    road3.surface = CRUSHED_STONE;
    road3.road_len = 100;
    road3.road_lines_num = 2;

    EXPECT_EQ(-5, rate_road(road3));
}

//find_road_qality

//Тест проверящий массив дорог со средним рейтингом BAD

TEST(find_road_quality, find_road_quality_test1) {
    Road_Information road[4];

    road[0].quality = GOOD;
    road[0].surface = SAND;
    road[0].road_len = 110;
    road[0].road_lines_num = 1;


    road[1].quality = TERRIBLE;
    road[1].surface = CONCRETE;
    road[1].road_len = 500;
    road[1].road_lines_num = 5;

    road[2].quality = NORMAL;
    road[2].surface = CRUSHED_STONE;
    road[2].road_len = 500;
    road[2].road_lines_num = 8;

    road[3].quality = BAD;
    road[3].surface = CRUSHED_STONE;
    road[3].road_len = 100;
    road[3].road_lines_num = 2;

    enum Road_quality quality = find_road_quality(road, 4);

    EXPECT_EQ(BAD, quality);
}

//Тест проверящий массив дорог со средним рейтингом BAD

TEST(find_road_quality, find_road_quality_test2) {
    Road_Information road[4];

    road[0].quality = GOOD;
    road[0].surface = CRUSHED_STONE;
    road[0].road_len = 500;
    road[0].road_lines_num = 3;


    road[1].quality = GOOD;
    road[1].surface = CONCRETE;
    road[1].road_len = 10;
    road[1].road_lines_num = 1;

    road[2].quality = NORMAL;
    road[2].surface = CRUSHED_STONE;
    road[2].road_len = 500;
    road[2].road_lines_num = 8;

    road[3].quality = BAD;
    road[3].surface = CRUSHED_STONE;
    road[3].road_len = 100;
    road[3].road_lines_num = 2;
    enum Road_quality quality = find_road_quality(road, 4);
    EXPECT_EQ(BAD, quality);
}

//Тест проверящий массив дорог со средним рейтингом EXCELLENT

TEST(find_road_quality, find_road_quality_test3) {
    Road_Information road[4];

    road[0].quality = GOOD;
    road[0].surface = ASHPALT;
    road[0].road_len = 110;
    road[0].road_lines_num = 1;


    road[1].quality = EXCELLENT;
    road[1].surface = CONCRETE;
    road[1].road_len = 500;
    road[1].road_lines_num = 5;

    road[2].quality = NORMAL;
    road[2].surface = CONCRETE;
    road[2].road_len = 500;
    road[2].road_lines_num = 8;

    road[3].quality = EXCELLENT;
    road[3].surface = ASHPALT;
    road[3].road_len = 100;
    road[3].road_lines_num = 2;

    enum Road_quality quality = find_road_quality(road, 4);
    EXPECT_EQ(EXCELLENT, quality);
}

//Проверка функции определения дорожного полотна по одноименной строке

TEST(find_surface, find_surface_test1) {

    char str1[] = "ASHPALT";

    enum Surface_type surface = find_surface(str1);

    EXPECT_EQ(ASHPALT, surface);

    char str2[] = "CONCRETE";

    surface = find_surface(str2);

    EXPECT_EQ(CONCRETE, surface);

    char str3[] = "CRUSHED_STONE";

    surface = find_surface(str3);

    EXPECT_EQ(CRUSHED_STONE, surface);

    char str4[] = "SAND";

    surface = find_surface(str4);

    EXPECT_EQ(SAND, surface);
}

//Проверка функции определения качества дороги по одноименной строке

TEST(find_quality, find_quality_test1) {

    char str1[] = "EXCELLENT";

    enum Road_quality quality = find_quality(str1);

    EXPECT_EQ(EXCELLENT, quality);

    char str2[] = "GOOD";

    quality = find_quality(str2);

    EXPECT_EQ(GOOD, quality);

    char str3[] = "NORMAL";

    quality = find_quality(str3);

    EXPECT_EQ(NORMAL, quality);

    char str4[] = "TERRIBLE";

    quality = find_quality(str4);

    EXPECT_EQ(TERRIBLE, quality);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}