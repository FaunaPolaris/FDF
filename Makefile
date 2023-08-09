NAME		=	fdf
CC		=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -g3 -ggdb
HEADER		=	-I./include/
MLX_LINK	=	-lXext -lX11 -lmlx -L minilibx/
MATH_LINK	=	-lm

SRCS_GRAPH	=	fp_graphical_init.c fp_graphical_end.c fp_putpixel.c
SRCS_GRAPH	+=	fp_butterfly.c fp_find_center.c

SRCS_ALL	=	$(addprefix graphics/,$(SRCS_GRAPH))

ANSI		=	\033[0
BOLD		=	;1
YELLOW		=	;33
MAGENTA		=	;35
CYAN		=	;36

TMAIN_MLX	=	tests/mlx_test.c
TMAIN_FORM	=	tests/formulas_test.c

all: $(NAME)

$(NAME): mlx_test formulas
	@echo

mlx_test:
	@$(CC) $(C_FLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_MLX) -o $@ $(MLX_LINK) $(MATH_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "mlx tests:" "Compiled"

formulas:
	@$(CC) $(C_GLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_FORM) -o $@ $(MLX_LINK) $(MATH_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "formulas" "Compiled"
	@echo
	@printf "%s:$(ANSI)$(MAGENTA)m%10s$(ANSI)m\n" "B" "butterfly_curve"

clean:
	@rm -rf $(OBJS_DIR)
	@printf "%-30s$(ANSI)$(CYAN)m%s;$(ANSI)m\n" "Objs directory:" "Removed"

fclean: clean
	@rm -rf $(NAME)
	@printf "%-30s$(ANSI)$(CYAN)m%s;$(ANSI)m\n" "Program:" "Removed"

re: fclean all
	@printf "$(ANSI)$(MAGENTA)m%-30s$(ANSI)m\n" "Starting recompilation"

.PHONY: all mlx_test formulas clean fclean re
