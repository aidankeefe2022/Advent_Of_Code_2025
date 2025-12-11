cmake_minimum_required(VERSION 4.0)
project(AdventOfCode2025 C)
enable_testing()

set(CMAKE_C_STANDARD 23)

# --- Main Advent of Code executable ---
add_executable(AdventOfCode2025
        tools/cust_fileReader/file_reader.c
        tools/Arena/Arena.c
        tools/Stack/Stack.c
        tools/Logger/logger.c
        day4/day4.c
        day4/day4_util.c
)

target_link_libraries(AdventOfCode2025 m)

add_executable(Day4_test
        tools/cust_fileReader/file_reader.c
        tools/Arena/Arena.c
        tools/Stack/Stack.c
        tools/Logger/logger.c
        day4/day4_util.c
        day4/test_day4.c

)

target_link_libraries(Day4_test m)


add_executable(Stack_Test
        tools/Stack/test.c
        tools/Stack/Stack.c
)

target_link_libraries(Stack_Test m)



add_test(NAME Day4_test COMMAND day4_test)
add_test(NAME StackTest COMMAND Stack_Test)