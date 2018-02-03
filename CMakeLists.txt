cmake_minimum_required(VERSION 3.7)
project(lem_in)

set(CMAKE_C_STANDARD 99)
FILE(GLOB libft_sources libft/*.c libft/*.h libft/get_next_line/*.c)

ADD_LIBRARY(libft.a STATIC ${libft_sources})

set(SOURCE_FILES main.c lemin.h building_way.c cheack_ways.c cheak_rooms.c check_links.c copy.c flipping.c get_next_line.c get_next_line.h
        help.c inter2.c loop_ants.c move_ants.c next_main.c start_end.c way.c)
add_executable(lem_in ${SOURCE_FILES})
target_link_libraries(lem_in libft.a)