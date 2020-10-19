cmake_minimum_required(VERSION 3.9.2)
project(HW_2)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_C_FLAGS "-Wall -Werror -pedantic -fprofile-arcs -ftest-coverage")
#set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -fprofile-arcs -ftest-coverage")

#set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -lm -fprofile-arcs -ftest-coverage -lgcov")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)



set(DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DSOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

set(INC_DIR ${DIR}/project/include)

set(SRC_DIR ${DIR}/project/src)

set(TESTS_DIR ${DIR}/tests)

include_directories("${GTEST_INCLUDE_DIRS}")
include_directories(include)

if(TRUE)
    add_executable(TEST
            tests/main.cpp
            ${SRC_DIR}/calculate_matrix.c
            ${INC_DIR}/utils.h
            )

    target_include_directories(TEST PUBLIC ${INC_DIR})

    target_link_libraries(TEST ${GTEST_LIBRARIES} Threads::Threads)


    enable_testing()
    add_test(NAME TEST COMMAND tests)
else()
    add_executable(HW_2
            ${SRC_DIR}/main.c
            ${SRC_DIR}/calculate_matrix.c
            ${INC_DIR}/utils.h
            )

    target_include_directories(HW_2 PUBLIC ${INC_DIR})
endif()