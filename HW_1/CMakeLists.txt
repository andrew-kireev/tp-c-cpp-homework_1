cmake_minimum_required(VERSION 3.15)
project(HW_1 C)

set(CMAKE_C_STANDARD 99)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(INC_DIR ${DIR}/include)

set(SRC_DIR ${DIR}/src)

add_executable(HW_1 ${SRC_DIR}/main.c ${SRC_DIR}/find_road_quality.c)

target_include_directories(HW_1 PUBLIC ${INC_DIR})