//
// Created by Andrew Kireev on 07.10.2020.
//

#ifndef HW_1_ROAD_INFORMATION_H
#define HW_1_ROAD_INFORMATION_H

#include <stdlib.h>

enum Surface_type {
    ASHPALT,
    CONCRETE,
    CRUSHED_STONE,
    SAND
};

enum Road_quality {
    EXCELLENT,
    GOOD,
    NORMAL,
    BAD,
    TERRIBLE
};

typedef struct
{
    size_t road_len;
    enum Surface_type surface;
    enum Road_quality quality;
    size_t road_lines_num;

} Road_Information;


size_t evaluate_road_quality(enum Road_quality quality);
int evaluate_road_surface(enum Surface_type surface);
int evaluate_road_len(size_t len);
int evaluate_amount_lines(size_t lines);
enum Road_quality final_quality(int rating);
size_t rate_road(const Road_Information road);
enum Road_quality find_road_quality(Road_Information* roads, size_t num);
void   print_quality(enum Road_quality quality);
void   print_surface(enum Surface_type surface);

#endif //HW_1_ROAD_INFORMATION_H
