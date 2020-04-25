cmake_minimum_required(VERSION 3.14)
project(21_fractal C)

set(CMAKE_C_STANDARD 99)

add_executable(21_fractal
        ./main.c
        ./vector3/vector3_a.c
        ./vector3/vector3_b.c
        ./rm/rm.c
        ./rm/rm_mxl.c
        ./rm/rm_ctrl.c
        ./rm/rm_ctrl_easy.c
        ./camera/camera.c
        ./scene/scene.c
        ./object/object.c
        ./scene/scene.c
        ./object/object_init_complex.c
        ./object/object_init_fractal.c
        ./open_cl/open_cl_error.c
        ./open_cl/open_cl.c
        ./open_cl/open_cl_init.c
        ./open_cl/open_cl_functions.c
        ./easy/easy.c
        ./ikido/ikido.c
        ./mouse/mouse.c rm/rm_ctrl_ikido.c)

target_include_directories(21_fractal
        PRIVATE /usr/local/include
        PRIVATE /usr/X11/include
        PRIVATE ../21_libft/includes
        PRIVATE ./vector3
        PRIVATE ./camera
        PRIVATE ./mlx
        PRIVATE ./color
        PRIVATE ./rm
        PRIVATE ./vector4
        PRIVATE ./object
        PRIVATE ./scene
        PRIVATE ./ray
        PRIVATE ./light
        PRIVATE ./open_cl
        PRIVATE ./vector2
        PRIVATE ./easy
        PRIVATE ./ikido)

target_link_directories(21_fractal
        PRIVATE /usr/local/lib
        PRIVATE /usr/X11/lib
        PRIVATE ../21_libft/)

target_link_libraries(21_fractal
        "ft"
        "mlx"
        "-framework OpenGL"
        "-framework OpenCL"
        "-framework AppKit")

