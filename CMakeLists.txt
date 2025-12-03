cmake_minimum_required(VERSION 4.0)
project(AdventOfCode2025 C)
enable_testing()

set(CMAKE_C_STANDARD 23)

# --- Main Advent of Code executable ---
add_executable(AdventOfCode2025
        cust_fileReader/file_reader.c
        Arena/Arena.c
        day2/day2_1.c
        day2/day2_utils.c
)

target_link_libraries(AdventOfCode2025 m)

# --- Separate test executable ---
add_executable(day2_test
        day2/test.c
        day2/day2_utils.c # <-- needed so update_scanner/check_pattern link correctly
        cust_fileReader/file_reader.c
        Arena/Arena.c
)

target_link_libraries(day2_test m)


add_test(NAME Day2Test COMMAND day2_test)