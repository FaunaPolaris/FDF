NAME		=	fdf
CC		=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -g3
HEADER		=	-I./include/
MLX_LINK	=	-L minilibx/ -lmlx -lX11 -lXext
MATH_LINK	=	-lm
LIBFT_LINK	=	-I./include/libft/header -L $(LIBFT) -lft
LIBFT		=	./include/libft/

SRCS_GRAPH	=	fp_graphical_init.c fp_graphical_end.c fp_putpixel.c
SRCS_GRAPH	+=	fp_butterfly.c fp_find_center.c fp_rect.c fp_putvertice.c
SRCS_GRAPH	+=	fp_rotxvertice.c fp_isometric.c fp_putline.c fp_putrect.c
SRCS_GRAPH	+=	fp_set_all.c fp_new_frame.c
SRCS_FDF	=	fdf_check_map.c fdf_draw_map.c fdf_apply_depth.c

SRCS_ALL	+=	$(addprefix graphics/,$(SRCS_GRAPH))
SRCS_ALL	+=	$(addprefix fdf_src/,$(SRCS_FDF))

ANSI		=	\033[0
BOLD		=	;1
YELLOW		=	;33
MAGENTA		=	;35
CYAN		=	;36

TMAIN_MLX	=	tests/mlx_test.c
TMAIN_MAP	=	tests/map_test.c
TMAIN_DRW	=	tests/draw_test.c
TMAIN_FORM	=	tests/formulas_test.c
TMAIN_CUBE	=	tests/cube_test.c

all: libft $(NAME) cube formulas

$(NAME):
	@echo
	@printf "%20s\n" "-----------"
	@printf "%25s\n" "FDF by: Fauna Polaris"
	@printf "%20s\n" "-----------"

libft: 
	@make -C $(LIBFT)

tests: libft mlx_test map_test draw_test

mlx_test:
	@$(CC) $(C_FLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_MLX) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "mlx_test" "Compiled"

formulas:
	@$(CC) $(C_GLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_FORM) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "formulas" "Compiled"
	@echo
	@printf "%s: $(ANSI)$(MAGENTA)m%.15s$(ANSI)m" " B" "butterfly_curve"
	@printf "%s: $(ANSI)$(MAGENTA)m%.15s$(ANSI)m" "| B" "butterfly_curve"
	@echo

map_test:
	@$(CC) $(C_FLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_MAP) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "map_test" "Compiled"

draw_test:
	@$(CC) $(C_FLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_DRW) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "draw_test" "Compiled"
cube:
	@$(CC) $(C_FLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_CUBE) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s$(ANSI)m\n" "Cube" "Compiled"

clean:
	@echo
	@rm -rf $(OBJS_DIR)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "Objects" "Cleaned"

clean_tests:
	@rm -rf mlx_test
	@rm -rf map_test
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "Tests" "Cleaned"

fclean: clean clean_tests
	@rm -rf $(NAME)
	@rm -rf formulas
	@rm -rf cube
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "Executables" "Cleaned"
	@make -C $(LIBFT) fclean
	@echo

re_tests: clean_tests tests

re: fclean all

.PHONY: all libft formulas cube clean fclean re \\
	tests draw_test map_test mlx_test clean_tests re_tests
