NAME		=	fdf
CC		=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -g3 -ggdb
MLX_LINK	=	-lXext -lX11 -lmlx -L minilibx/

SRCS_GRAPH	=	fp_graphical_init.c fp_graphical_end.c fp_pixel_put.c
SRCS_ALL	=	$(addprefix graphics/,$(SRCS_GRAPH))

ANSI		=	\033[0
BOLD		=	;1
YELLOW		=	;33
MAGENTA		=	;35
CYAN		=	;36

MAIN		=
TMAIN_MLX	=	tests/mlx_test.c

all: $(NAME)
	echo

$(NAME):
	@$(CC) $(C_FLAGS) $(SRCS_ALL) -I include $(MAIN) -o $(NAME) $(MLX_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m/n" "FDF:" "Compiled"

mlx_test:
	@$(CC) $(C_FLAGS) $(SRCS_ALL) -Iinclude $(TMAIN_MLX) -o $(NAME) $(MLX_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "mlx tests:" "Compiled"

clean:
	@rm -rf $(OBJS_DIR)
	@printf "%-30s$(ANSI)$(CYAN)m%s;$(ANSI)m\n" "Objs directory:" "Removed"

fclean:
	@rm -rf $(NAME)
	@printf "%-30s$(ANSI)$(CYAN)m%s;$(ANSI)m\n" "Program:" "Removed"

re: fclean all
	@printf "$(ANSI)$(MAGENTA)m%-30s$(ANSI)m\n" "Starting recompilation"

.PHONY: all mlx_test clean fclean re
