//
// Created by Andrew Kireev on 07.10.2020.
//

#include <stdio.h>
#include <string.h>
#include "road_information.h"

void procces_input(size_t* n)
{
    int res = scanf("%zd", n);
    if (!res)
    {
        printf("Введите корректно число дорог!");
        procces_input(n);
    }
}

enum Surface_type find_surface(char *str)
{
    if (strcmp(str, "ASHPALT") == 0)
        return ASHPALT;
    if (strcmp(str, "CONCRETE") == 0)
        return CONCRETE;
    if (strcmp(str, "CRUSHED_STONE") == 0)
        return CRUSHED_STONE;
//    if (strcmp(str, "SAND") == 0)
    return SAND;
}

enum Road_quality find_quality(char *str)
{
    if (strcmp(str, "EXCELLENT") == 0)
        return EXCELLENT;
    if (strcmp(str, "GOOD") == 0)
        return GOOD;
    if (strcmp(str, "NORMAL") == 0)
        return NORMAL;
    if (strcmp(str, "BAD") == 0)
        return BAD;
//    if (strcmp(str, "TERRIBLE") == 0)
    return TERRIBLE;
}

void filling_struct(Road_Information* roads, size_t num)
{
    printf("%s\n", "Введите информацию о дороге: длинну, качество дороги, тип дорожного полотна и число полос");
    for (size_t i = 0; i != num; i++)
    {
        char surface[10];
        char quality[10];
        printf("Введите информацию о %zu дороге\n", i);
        scanf("%zd", &roads[i].road_len);
        scanf("%s",quality);
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


/*
 300
NORMAL
CONCRETE
2
 49
NORMAL
ASHPALT
3
 = 45
 */

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
