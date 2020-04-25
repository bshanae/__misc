cmake_minimum_required(VERSION 3.13)
project(fdf_v1 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

include_directories(    /usr/local/include
                        ./libft/includes/
                        ./error/
                        ./color/
                        ./quaternion/
                        ./point/
                        ./some_math/
                        ./map/
                        ./vo/)

link_directories(       /usr/local/include
                        /usr/local/lib
                        ./libft)

add_executable(         fdf_v1
                        ./error/error.c
                        ./color/color.c
                        ./quaternion/quaternion.c
                        ./point/point.c
                        ./some_math/some_math.c
                        ./map/map_main.c
                        ./map/map_tree_utils.c
                        ./map/map_tree_render.c
                        map/map_functions.c
                        ./map/map_iso.c
                        ./map/map_read.c
                        ./map/map_read_utils.c
                        ./map/map_wu.c
                        ./vo/main.c
                        ./vo/vo_main.c
                        ./vo/vo_control.c
                        ./vo/vo_terminal_main.c
                        ./vo/vo_terminal_functions.c
                        ./vo/vo_terminal_utils.c
                        ./vo/vo_term_translate.c )

target_link_libraries(  fdf_v1
                        "ft"
                        "mlx"
                        "-framework OpenGL"
                        "-framework AppKit")
