//
// Created by Andrew Kireev on 07.10.2020.
//

#include "road_information.h"
#include <stdio.h>

size_t evaluate_road_quality(enum Road_quality quality)
{
    if (quality == EXCELLENT)
        return 80;
    if (quality == GOOD)
        return 60;
    if (quality == NORMAL)
        return 40;
    if (quality == BAD)
        return 20;
    return 0;
}

int evaluate_road_surface(enum Surface_type surface)
{
    if (surface == CONCRETE)
        return 15;
    if (surface == ASHPALT)
        return 0;
    if (surface == SAND)
        return -20;
    return -35;
}

int evaluate_road_len(size_t len)
{
    if (len >= 200)
        return 20;
    if (len >= 100)
        return 10;
    if (len < 50)
        return -10;
    return 0;
}

int evaluate_amount_lines(size_t lines)
{
    if (lines == 3)
        return 5;
    if (lines == 4)
        return 10;
    if (lines < 2)
        return -5;
    return 0;
}

enum Road_quality final_quality(size_t rating)
{
    printf("rating = %d\n", rating);
    if (rating >= 81)
        return EXCELLENT;
    if (rating >= 61)
        return GOOD;
    if (rating >= 41)
        return NORMAL;
    if (rating >= 21)
        return BAD;
    return TERRIBLE;
}

size_t rate_road(const Road_Information road)
{
    size_t rating = 0;

    rating += evaluate_road_quality(road.quality);
    rating += evaluate_road_surface(road.surface);
    rating += evaluate_road_len(road.road_len);
    rating += evaluate_amount_lines(road.road_lines_num);
    return rating;
}

enum Road_quality find_road_quality(Road_Information* roads, size_t num)
{
    size_t rating = 0;

    for (int i = 0; i != num; i++)
        rating += rate_road(roads[i]);

    return final_quality(rating / num);
}

void   print_quality(enum Road_quality quality)
{
    if (quality == EXCELLENT)
        printf("%s\n", "EXCELLENT");
    if (quality == GOOD)
        printf("%s\n", "GOOD");
    if (quality == NORMAL)
        printf("%s\n", "NORMAL");
    if (quality == BAD)
        printf("%s\n", "BAD");
    if (quality == TERRIBLE)
        printf("%s\n", "TERRIBLE");
}

void   print_surface(enum Surface_type surface)
{
    if (surface == SAND)
        printf("%s\n", "SAND");
    if (surface == CRUSHED_STONE)
        printf("%s\n", "CRUSHED_STONE");
    if (surface == CONCRETE)
        printf("%s\n", "CONCRETE");
    if (surface == ASHPALT)
        printf("%s\n", "ASHPALT");
}

