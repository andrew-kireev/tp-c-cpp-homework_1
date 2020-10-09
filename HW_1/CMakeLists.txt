cmake_minimum_required(VERSION 3.15)
project(HW_1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(INC_DIR ${DIR}/project/include)

set(SRC_DIR ${DIR}/project/src)

set(TESTS_DIR ${DIR}/tests)

include_directories("${GTEST_INCLUDE_DIRS}")
include_directories(include)

add_executable(HW_1
        ${SRC_DIR}/main.c
        ${INC_DIR}/road_information.h
        ${SRC_DIR}/find_road_quality.c)

target_include_directories(HW_1 PUBLIC ${INC_DIR})


add_executable(tests
        ${INC_DIR}/road_information.h
        ${SRC_DIR}/find_road_quality.c
        ${TESTS_DIR}/main.cpp)

target_include_directories(tests PUBLIC ${INC_DIR})

target_link_libraries(tests ${GTEST_LIBRARIES} Threads::Threads)


enable_testing()
add_test(tests "./tests")