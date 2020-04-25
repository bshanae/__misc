all : lem-in gui

lem-in :
	@make test -C ./build_lem_in
	
gui :
	@make test -C ./build_gui

clean :
	@make clean -C ./build_lem_in
	@make clean -C ./build_gui

fclean :
	@make fclean -C ./build_lem_in
	@make fclean_no_extern -C ./build_gui

re :
	@make re -C ./build_lem_in
	@make re_no_extern -C ./build_gui


.PHONY : lem-in gui clean fclean re
