//
// Created by Andrew Kireev on 07.10.2020.
//

#include <stdio.h>
#include "road_information.h"

void procces_input(size_t* n) {
    int res = scanf("%zd", n);
    if (!res) {
        printf("Введите корректно число дорог!");
        procces_input(n);
    }
}

void filling_struct(Road_Information* roads, size_t num) {
    printf("%s\n", "Введите информацию о дороге: длинну, качество дороги, "
                   "тип дорожного полотна и число полос");
    for (size_t i = 0; i != num; i++) {
        char surface[10];
        char quality[10];
        printf("Введите информацию о %zu дороге\n", i);
        scanf("%zd", &roads[i].road_len);
        scanf("%s", quality);
        scanf("%s", surface);
        scanf("%zu", &roads[i].road_lines_num);
        roads[i].surface = find_surface(surface);
        roads[i].quality = find_quality(quality);
        printf("len = %zu\n", roads[i].road_len);
        print_quality(roads[i].quality);
        print_surface(roads[i].surface);
        printf("lines = %zu\n", roads[i].road_lines_num);
    }
}

int main() {
    printf("%s\n", "Введите количество дорог");
    size_t n;
    procces_input(&n);
    printf("%zu", n);
    Road_Information road_info[n];
    filling_struct(road_info, n);

    print_quality(find_road_quality(road_info, n));
    return 0;
}
