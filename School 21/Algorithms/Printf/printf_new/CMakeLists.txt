cmake_minimum_required(VERSION 3.14)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

include_directories(        ./utils/
                            ./ftp_buffer/
                            ./ftp_format_in/
                            ./ftp_get_arg/
                            ./ftp_format_out/
                            ./ftp_format_out_whole/
                            ./ftp_format_out_real/
                            ./ftp_whitespaces/
                            ./long/
                            ./ft/
                            ./ftp_cmd/
                            ./ftp_control/
                            ./ftp_format_in/
                            ./ftp_format_data/
                            ./ftp_format_in/
                            ./libft_standart
                            ./libft_vector
                            ../../21_libft/libft/includes/)

link_directories(            ../../21_libft/libft)


add_executable(             ft_printf
                            ./ft/ft_printf.c
                            ./ftp_buffer/ftp_buffer_functions.c
                            ./ftp_buffer/ftp_buffer_main.c
                            ./ftp_control/ftp_control_definition.c
                            ./ftp_control/ftp_control_functions.c
                            ./ftp_format_data/ftp_format_data.c
                            ./ftp_format_data/ftp_format_data_default.c
                            ./ftp_format_data/ftp_format_data_long.c
                            ./ftp_format_data/ftp_format_data_short.c
                            ./ftp_format_in/ftp_format_additional.c
                            ./ftp_format_in/ftp_format_in.c
                            ./ftp_format_in/ftp_format_in_flags.c
                            ./ftp_format_in/ftp_format_in_precision.c
                            ./ftp_format_in/ftp_format_in_size.c
                            ./ftp_format_in/ftp_format_in_type.c
                            ./ftp_format_in/ftp_format_in_width.c
                            ./ftp_format_out/ftp_format_out.c
                            ./ftp_format_out/ftp_format_out_char.c
                            ./ftp_format_out/ftp_format_out_ptr.c
                            ./ftp_format_out/ftp_format_out_str.c
                            ./ftp_format_out_real/format_out_real_exceptions.c
                            ./ftp_format_out_real/ftp_format_out_real.c
                            ./ftp_format_out_real/ftp_format_out_real_convert.c
                            ./ftp_format_out_real/ftp_format_out_real_init.c
                            ./ftp_format_out_real/ftp_format_out_real_out.c
                            ./ftp_format_out_real/ftp_format_out_real_round.c
                            ./ftp_format_out_whole/ftp_format_out_whole.c
                            ./ftp_format_out_whole/ftp_format_out_whole_init.c
                            ./ftp_format_out_whole/ftp_format_out_whole_out.c
                            ./ftp_format_out_whole/ftp_format_out_whole_process.c
                            ./long/long_basic.c
                            ./long/long_functions.c
                            ./main/main0.c
                            ./utils/utils.c
                            ./ftp_control/ftp_control_color.c
                            ./ftp_control/ftp_control_functor.c
        ftp_control/ftp_control_special.c
#                            ../../21_libft/libft/vector/sources/vector_at.c
#                            ../../21_libft/libft/vector/sources/vector_clear.c
#                            ../../21_libft/libft/vector/sources/vector_create.c
#                            ../../21_libft/libft/vector/sources/vector_erase.c
#                            ../../21_libft/libft/vector/sources/vector_destroy.c
#                            ../../21_libft/libft/vector/sources/vector_resize.c
#                            ../../21_libft/libft/vector/sources/vector_insert.c
#                            ../../21_libft/libft/vector/sources/vector_pop_back.c
#                            ../../21_libft/libft/vector/sources/vector_push_back.c
#                            ../../21_libft/libft/vector/sources/vector_print.c
#                            ../../21_libft/libft/vector/sources/vector_find.c
#                            ../../21_libft/libft/includes/libft_vector.h
                            )

target_link_libraries(ft_printf "ft")