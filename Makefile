NAME		=	fdf
CC		=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -g3 -ggdb
HEADER		=	-I./include/
MLX_LINK	=	-lXext -lX11 -lmlx -L minilibx/
MATH_LINK	=	-lm
LIBFT_LINK	=	-I./include/libft/header -L $(LIBFT) -lft
LIBFT		=	./include/libft/

SRCS_FDF	=	fp_open_map.c fp_close_map.c fp_draw_map.c

SRCS_GRAPH	=	fp_graphical_init.c fp_graphical_end.c fp_putpixel.c
SRCS_GRAPH	+=	fp_butterfly.c fp_find_center.c fp_rect.c fp_putvertice.c
SRCS_GRAPH	+=	fp_rotxvertice.c fp_isometric.c fp_putline.c fp_putrect.c
SRCS_GRAPH	+=	fp_set_all.c

SRCS_ALL	=	$(addprefix srcs/,$(SRCS_FDF))
SRCS_ALL	+=	$(addprefix graphics/,$(SRCS_GRAPH))

ANSI		=	\033[0
BOLD		=	;1
YELLOW		=	;33
MAGENTA		=	;35
CYAN		=	;36

MAIN		=	srcs/main.c
TMAIN_MLX	=	tests/mlx_test.c
TMAIN_FORM	=	tests/formulas_test.c
TMAIN_CUBE	=	tests/cube_test.c

all: libft $(NAME) mlx_test cube formulas

$(NAME):
	@$(CC) $(C_FLAGS) $(SRCS_ALL) $(HEADER) $(MAIN) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@echo
	@printf "%20s\n" "-----------"
	@printf "%25s\n" "FDF by: Fauna Polaris"
	@printf "%20s\n" "-----------"

libft: 
	@make -C $(LIBFT)

mlx_test:
	@$(CC) $(C_FLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_MLX) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "mlx tests:" "Compiled"

formulas:
	@$(CC) $(C_GLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_FORM) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "formulas" "Compiled"
	@echo
	@printf "%s: $(ANSI)$(MAGENTA)m%.15s$(ANSI)m" " B" "butterfly_curve"
	@printf "%s: $(ANSI)$(MAGENTA)m%.15s$(ANSI)m" "| B" "butterfly_curve"
	@echo

cube:
	@$(CC) $(C_FLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_CUBE) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s$(ANSI)m\n" "Cube" "Compiled"

clean:
	@echo
	@rm -rf $(OBJS_DIR)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "Objects" "Cleaned"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf formulas
	@rm -rf mlx_test
	@rm -rf cube
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "Executables" "Cleaned"
	@make -C $(LIBFT) fclean
	@echo

re: fclean all

.PHONY: all libft mlx_test formulas cube clean fclean re
