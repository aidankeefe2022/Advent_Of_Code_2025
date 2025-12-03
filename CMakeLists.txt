cmake_minimum_required(VERSION 4.0)
project(AdventOfCode2025 C)
enable_testing()

set(CMAKE_C_STANDARD 23)

# --- Main Advent of Code executable ---
add_executable(AdventOfCode2025
        cust_fileReader/file_reader.c
        Arena/Arena.c
        day3/day3.c
        day3/day3_utils.c
        day3/day3_utils.h
)

target_link_libraries(AdventOfCode2025 m)

# --- Separate test executable ---
add_executable(day3_test
        day3/test.c
        day3/day3_utils.c # <-- needed so update_scanner/check_pattern link correctly
        cust_fileReader/file_reader.c
        Arena/Arena.c
)

target_link_libraries(day3_test m)


add_test(NAME Day3Test COMMAND day3_test)