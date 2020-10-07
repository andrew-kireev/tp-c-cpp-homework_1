#include <stdio.h>
#include "road_information.h"

int main() {
    Road_Information road_info[5];
    road_info[0].quality = GOOD;
    road_info[0].surface = CONCRETE;
    road_info[0].road_len = 40;
    road_info[0].road_lines_num = 2;
    print_quality(find_road_quality(road_info, 1));
    return 0;
}
