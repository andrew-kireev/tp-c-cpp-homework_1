cmake_minimum_required(VERSION 3.9.2)
project(HW_2 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "-Wall -O3 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "-Wall -O3 -fprofile-arcs -ftest-coverage")

#set(CMAKE_C_FLAGS "-Wall -Werror -O3")
#set(CMAKE_CXX_FLAGS "-Wall -Werror -O3")

#set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -lm -fprofile-arcs -ftest-coverage -lgcov")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)



set(DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DSOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

set(INC_DIR ${DIR}/project/include)

set(SRC_DIR ${DIR}/project/src)

set(TESTS_DIR ${DIR}/tests)

include_directories("${GTEST_INCLUDE_DIRS}")
include_directories(project/include)

add_library(one_process STATIC
        ${INC_DIR}/utils.h
        ${SRC_DIR}/one/calculate_matrix.c
        ${SRC_DIR}/utils.c
        ${INC_DIR}/one/one_proc_utils.h)

add_library(multi_process SHARED
        ${INC_DIR}/multi/multi_process_utils.h
        ${SRC_DIR}/multi/mult_proc_calculate_matrix.c
        ${SRC_DIR}/utils.c)

add_executable(TEST
    tests/test_one_process.cpp)

target_include_directories(TEST PUBLIC ${INC_DIR})

target_link_libraries(TEST ${GTEST_LIBRARIES} Threads::Threads one_process multi_process)

add_executable(TEST_VALGRIND
    tests/tests_for_valgrind.cpp)

target_include_directories(TEST_VALGRIND PUBLIC ${INC_DIR})

target_link_libraries(TEST_VALGRIND ${GTEST_LIBRARIES} Threads::Threads one_process multi_process)


enable_testing()
add_test(NAME TEST_ONE COMMAND tests1)
add_test(NAME TEST_VALGRIND COMMAND tests2)
add_executable(HW_2_ONE_PROC
    ${SRC_DIR}/one/main.c)

add_executable(HW_2_MULTI_PROC
    ${SRC_DIR}/multi/main.c)

target_link_libraries(HW_2_ONE_PROC one_process)
target_link_libraries(HW_2_MULTI_PROC multi_process)

target_include_directories(HW_2_ONE_PROC PUBLIC ${INC_DIR})
target_include_directories(HW_2_MULTI_PROC PUBLIC ${INC_DIR})