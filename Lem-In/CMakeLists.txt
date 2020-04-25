cmake_minimum_required(VERSION 3.14)
project(lem_in C)

set(CMAKE_C_STANDARD 99)

#	#	#	#	#	GLOBAL	#	#	#	#	#

include_directories(
	./libft/includes
	./source_global/global_error
	./source_global/global_buffer
	./source_global/global_bool
	./source_global/global_range
	./source_global/global_command
	./source_global/global_room
	./source_global/global_parser
	./source_global/global_map
	./source_global/global_trace)

link_directories(
	./libft)

link_libraries(
	"ft")

set(SOURCE_GLOBAL_ERROR
	./source_global/global_error/global_print_x.c
	./source_global/global_error/global_raise_x.c
	./source_global/global_error/global_assert_x.c
	./source_global/global_error/global_malloc.c
	./source_global/global_error/global_gnl.c)

set(SOURCE_GLOBAL_BUFFER
	./source_global/global_buffer/global_buffer_x.c)

set(SOURCE_GLOBAL_ROOM
	./source_global/global_room/global_room_x.c)

set(SOURCE_GLOBAL_MAP
	./source_global/global_map/global_map_create.c
	./source_global/global_map/global_map_destroy.c
	source_global/global_map/global_map_verify_x.c
	./source_global/global_map/global_map_parse_x.c
	./source_global/global_map/global_map_parse_part_x.c
	./source_global/global_map/global_map_parse.c
	./source_global/global_map/global_map_find_room.c
	./source_global/global_map/global_map_temp_x.c
	./source_global/global_map/global_map_f.c
	./source_global/global_map/global_map_info.c)

set(SOURCE_GLOBAL_PARSER
	./source_global/global_parser/global_parser_pass_x.c
	./source_global/global_parser/global_parser_is_x.c
	./source_global/global_parser/global_parser_get_x.c
	./source_global/global_parser/global_parser_verify_name.c)

set(SOURCE_GLOBAL_TRACE
	./source_global/global_trace/global_trace_create.c
	./source_global/global_trace/global_trace_destroy.c
	./source_global/global_trace/global_trace_parse.c
	./source_global/global_trace/global_trace_parse_x.c
	./source_global/global_trace/global_trace_info.c)

set(SOURCE_GLOBAL
	${SOURCE_GLOBAL_ERROR}
	${SOURCE_GLOBAL_BUFFER}
	${SOURCE_GLOBAL_ROOM}
	${SOURCE_GLOBAL_PARSER}
	${SOURCE_GLOBAL_MAP}
	${SOURCE_GLOBAL_TRACE})

#	#	#	#	#	LEM_IN	#	#	#	#	#

include_directories(
	./source_main/
	./source_lem_in/lem_in_plugin
	./source_lem_in/lem_in_state
	./source_lem_in/lem_in_main
	./source_lem_in/lem_in_info
	./source_lem_in/lem_in_flags
	./source_lem_in/lem_in_eval
	./source_lem_in/lem_in_work)

link_directories(
	./libft)

link_libraries(
	"ft")

set(SOURCE_LEM_IN_MAIN
	./source_main/lem_in_main.c
	./source_lem_in/lem_in_main/lem_in_main_new.c
	./source_lem_in/lem_in_main/lem_in_main_delete.c
	./source_lem_in/lem_in_main/lem_in_main_load.c)

set(SOURCE_LEM_IN_FLAGS
	./source_lem_in/lem_in_flags/lem_in_flags.c)

set(SOURCE_LEM_IN_INFO
	./source_lem_in/lem_in_info/lem_in_info_x.c
	./source_lem_in/lem_in_info/lem_in_print_x.c)

set(SOURCE_LEM_IN_WORK
	./source_lem_in/lem_in_work/lem_in_work.c
	./source_lem_in/lem_in_work/lem_in_bfs.c
	./source_lem_in/lem_in_work/lem_in_bfs_x.c
	./source_lem_in/lem_in_work/lem_in_parent_x.c
	./source_lem_in/lem_in_work/lem_in_bhandari.c
	./source_lem_in/lem_in_work/lem_in_solve_conflict.c
	./source_lem_in/lem_in_work/lem_in_backtrack.c
	./source_lem_in/lem_in_work/lem_in_lock_x.c
	./source_lem_in/lem_in_work/lem_in_out.c)

set(SOURCE_LEM_IN_EVAL
	./source_lem_in/lem_in_eval/lem_in_eval_create.c
	./source_lem_in/lem_in_eval/lem_in_eval_destroy.c)

add_executable(lem_in
	${SOURCE_GLOBAL}
	${SOURCE_LEM_IN_MAIN}
	${SOURCE_LEM_IN_FLAGS}
	${SOURCE_LEM_IN_INFO}
	${SOURCE_LEM_IN_WORK}
	${SOURCE_LEM_IN_EVAL})

#	#	#	#	#	GUI	#	#	#	#	#

#set(BREW_CELLAR /usr/local/Cellar)
set(BREW_CELLAR ~/.brew/Cellar)

include_directories(
	${BREW_CELLAR}/sdl2/2.0.10/include/SDL2/
	${BREW_CELLAR}/sdl2_image/2.0.5/include/SDL2
	${BREW_CELLAR}/sdl2_ttf/2.0.15/include/SDL2/)

link_directories(
	${BREW_CELLAR}/sdl2/2.0.10/lib
	${BREW_CELLAR}/sdl2_image/2.0.5/lib
	${BREW_CELLAR}/sdl2_ttf/2.0.15/lib)

link_libraries(
	"SDL2-2.0.0"
	"SDL2_image"
	"SDL2_ttf")

include_directories(
	./source_gui/
	./source_gui/gui_plugin
	./source_gui/gui_main
	./source_gui/gui_math
	./source_gui/gui_sdl
	./source_gui/gui_x
	./source_gui/gui_color
	./source_gui/gui_buffer
	./source_gui/gui_font
	./source_gui/gui_settings
	./source_gui/gui_object_type
	./source_gui/gui_object
	./source_gui/gui_object_x
	./source_gui/gui_object_x_plot
	./source_gui/gui_object_x_bundle
	./source_gui/gui_map
	./source_gui/gui_trace
	./source_gui/gui_map_with_trace
	./source_gui/gui_ptr
	./source_gui/gui_event
	./source_gui/gui_callback
	./source_gui/gui_callback_list
	./source_gui/gui_class
	./source_gui/gui_widget
	./source_gui/gui_button
	./source_gui/gui_button_implementation
	./source_gui/gui_system
	./source_gui/gui_list
	./source_gui/gui_list_settings
	./source_gui/gui_surface)

set(SOURCE_GUI_PLUGIN
	./source_gui/gui_plugin/gui_plugin.c)

set(SOURCE_GUI_MAIN
	./source_main/gui_main.c
	./source_gui/gui_main/gui_main_new.c
	./source_gui/gui_main/gui_main_delete.c
	./source_gui/gui_main/gui_main_loop.c
	./source_gui/gui_main/gui_main_callback_x_a.c
	./source_gui/gui_main/gui_main_callback_x_b.c
	./source_gui/gui_main/gui_main_render.c)

set(SOURCE_GUI_MATH
	./source_gui/gui_math/gui_math.c)

set(SOURCE_GUI_SDL
	./source_gui/gui_sdl/gui_sdl_x.c
	./source_gui/gui_sdl/gui_sdl_timer_x.c)

set(SOURCE_GUI_COLOR
	./source_gui/gui_color/gui_color_x.c)

set(SOURCE_GUI_BUFFER
	./source_gui/gui_buffer/gui_buffer_new_x.c
	./source_gui/gui_buffer/gui_buffer_delete.c
	./source_gui/gui_buffer/gui_buffer_set.c
	./source_gui/gui_buffer/gui_buffer_clear.c
	./source_gui/gui_buffer/gui_buffer_copy_x.c)

set(SOURCE_GUI_FONT
	./source_gui/gui_font/gui_font_x.c)

set(SOURCE_GUI_SETTINGS_OUT
	./source_gui/gui_settings/gui_settings_x.c)

set(SOURCE_GUI_OBJECT
	./source_gui/gui_object/gui_object.c)

set(SOURCE_GUI_OBJECT_X_PLOT
	./source_gui/gui_object_x_plot/gui_object_point_i_plot.c
	./source_gui/gui_object_x_plot/gui_object_line_naa_plot.c
	./source_gui/gui_object_x_plot/gui_object_line_aa_plot.c
	./source_gui/gui_object_x_plot/gui_object_circle_plot.c
	./source_gui/gui_object_x_plot/gui_object_hint_plot.c
	./source_gui/gui_object_x_plot/gui_object_hint_helper_triangle.c
	./source_gui/gui_object_x_plot/gui_object_hint_helper_rectangle.c
	./source_gui/gui_object_x_plot/gui_object_hint_helper_corners.c
	./source_gui/gui_object_x_plot/gui_object_hint_helper_borders.c
	./source_gui/gui_object_x_plot/gui_object_point_f_plot.c
	./source_gui/gui_object_x_plot/gui_object_line_plot.c
	./source_gui/gui_object_x_plot/gui_object_rectangle_plot.c)

set(SOURCE_GUI_OBJECT_X_BUNDLE
	./source_gui/gui_object_x_bundle/gui_object_point_i_bundle.c
	./source_gui/gui_object_x_bundle/gui_object_point_f_bundle.c
	./source_gui/gui_object_x_bundle/gui_object_line_bundle.c
	./source_gui/gui_object_x_bundle/gui_object_circle_bundle.c
	./source_gui/gui_object_x_bundle/gui_object_hint_bundle.c
	./source_gui/gui_object_x_bundle/gui_object_rectangle_bundle.c)

set(SOURCE_GUI_MAP
	./source_gui/gui_map/gui_map_delete.c
	./source_gui/gui_map/gui_map_render_back.c
	./source_gui/gui_map/gui_map_render_front.c
	./source_gui/gui_map/gui_map_new.c
	./source_gui/gui_map/gui_map_examine_widget.c)

set(SOURCE_GUI_TRACE
	./source_gui/gui_trace/gui_trace_internal_x.c
	./source_gui/gui_trace/gui_trace_step_x.c
	./source_gui/gui_trace/gui_trace_new.c
	./source_gui/gui_trace/gui_trace_delete.c
	./source_gui/gui_trace/gui_trace_render_x.c)

set(SOURCE_GUI_MAP_WITH_TRACE
	./source_gui/gui_map_with_trace/gui_map_with_trace_x.c
	./source_gui/gui_map_with_trace/gui_map_with_trace_shift.c
	./source_gui/gui_map_with_trace/gui_map_with_trace_callback_x.c)

set(SOURCE_GUI_PTR
	./source_gui/gui_ptr/gui_ptr_x.c)

set(SOURCE_GUI_EVENT
	./source_gui/gui_event/gui_event_x.c)

set(SOURCE_GUI_CALLBACK
	./source_gui/gui_callback/gui_callback_x.c)

set(SOURCE_GUI_CALLBACK_LIST
	./source_gui/gui_callback_list/gui_callback_list_new.c
	./source_gui/gui_callback_list/gui_callback_list_delete.c
	./source_gui/gui_callback_list/gui_callback_list_push.c
	./source_gui/gui_callback_list/gui_callback_list_run.c
	./source_gui/gui_callback_list/gui_callback_list_pop.c
	./source_gui/gui_callback_list/gui_callback_list_test.c)

set(SOURCE_GUI_CLASS
	./source_gui/gui_class/gui_class_cast.c
	./source_gui/gui_class/gui_class_info_set.c
	./source_gui/gui_class/gui_class_cast_x.c
	./source_gui/gui_class/gui_class_pattern_get.c)

set(SOURCE_GUI_WIDGET
	./source_gui/gui_widget/gui_widget_new.c
	./source_gui/gui_widget/gui_widget_delete.c
	./source_gui/gui_widget/gui_widget_callback_x.c)

set(SOURCE_GUI_BUTTON
	./source_gui/gui_button/gui_button_new.c
	./source_gui/gui_button/gui_button_callback_x.c
	./source_gui/gui_button/gui_button_test_x.c)

set(SOURCE_GUI_BUTTON_IMPLEMENTATION
	./source_gui/gui_button_implementation/gui_button_circle_x.c
	./source_gui/gui_button_implementation/gui_button_rectangle_x.c
	./source_gui/gui_button_implementation/gui_button_room_x.c
	./source_gui/gui_button_implementation/gui_button_ant_x.c
	./source_gui/gui_button_implementation/gui_button_list_x.c
	./source_gui/gui_button_implementation/gui_button_icon_new.c
	./source_gui/gui_button_implementation/gui_button_icon_render.c
	./source_gui/gui_button_implementation/gui_button_text_x.c)

set(SOURCE_GUI_SYSTEM
	./source_gui/gui_system/gui_system_create.c
	./source_gui/gui_system/gui_system_destroy.c
	./source_gui/gui_system/gui_system_signal_x.c
	./source_gui/gui_system/gui_system_add.c
	./source_gui/gui_system/gui_system_remove.c)

set(SOURCE_GUI_LIST
	./source_gui/gui_list/gui_list_new.c
	./source_gui/gui_list/gui_list_internal_callback_render.c
	./source_gui/gui_list/gui_list_internal_load_x.c
	./source_gui/gui_list/gui_list_internal_callback_x.c
	./source_gui/gui_list/gui_list_push.c
	./source_gui/gui_list/gui_list_select.c
	./source_gui/gui_list/gui_list_internal_update_block.c)

set(SOURCE_GUI_LIST_SETTINGS
	./source_gui/gui_list_settings/gui_list_settings_x.c)

set(SOURCE_GUI_SURFACE
	./source_gui/gui_surface/gui_surface_new.c
	./source_gui/gui_surface/gui_surface_test_x.c
	./source_gui/gui_surface/gui_surface_render.c)

add_executable(gui
	${SOURCE_GLOBAL}
	${SOURCE_GUI_PLUGIN}
	${SOURCE_GUI_MAIN}
	${SOURCE_GUI_MAIN_SET}
	${SOURCE_GUI_MATH}
	${SOURCE_GUI_BUFFER}
	${SOURCE_GUI_FONT}
	${SOURCE_GUI_SETTINGS_OUT}
	${SOURCE_GUI_MAP}
	${SOURCE_GUI_TRACE}
	${SOURCE_GUI_MAP_WITH_TRACE}
	${SOURCE_GUI_SDL}
	${SOURCE_GUI_COLOR}
	${SOURCE_GUI_OBJECT}
	${SOURCE_GUI_OBJECT_X_PLOT}
	${SOURCE_GUI_OBJECT_X_BUNDLE}
	${SOURCE_GUI_PTR}
	${SOURCE_GUI_EVENT}
	${SOURCE_GUI_CALLBACK}
	${SOURCE_GUI_CALLBACK_LIST}
	${SOURCE_GUI_CLASS}
	${SOURCE_GUI_WIDGET}
	${SOURCE_GUI_BUTTON}
	${SOURCE_GUI_BUTTON_IMPLEMENTATION}
	${SOURCE_GUI_SYSTEM}
	${SOURCE_GUI_LIST}
	${SOURCE_GUI_LIST_SETTINGS}
	${SOURCE_GUI_SURFACE})
