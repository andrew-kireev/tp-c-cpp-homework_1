cmake_minimum_required(VERSION 3.9.2)
project(HW_1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "-Wall -Werror -pedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -fprofile-arcs -ftest-coverage")

#set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -lm -fprofile-arcs -ftest-coverage -lgcov")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)



set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(INC_DIR ${DIR}/project/include)

set(SRC_DIR ${DIR}/project/src)

set(TESTS_DIR ${DIR}/tests)

include_directories("${GTEST_INCLUDE_DIRS}")
include_directories(include)

if(TRUE)
    add_executable(TEST
            ${INC_DIR}/road_information.h
            ${SRC_DIR}/find_road_quality.c
            tests/main.cpp)

    target_include_directories(TEST PUBLIC ${INC_DIR})

    target_link_libraries(TEST ${GTEST_LIBRARIES} Threads::Threads)


    enable_testing()
    add_test(NAME TEST COMMAND tests)
else()
    add_executable(HW_1
            ${SRC_DIR}/main.c
            ${INC_DIR}/road_information.h
            ${SRC_DIR}/find_road_quality.c)

    target_include_directories(HW_1 PUBLIC ${INC_DIR})
endif()
