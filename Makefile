NAME		=	fdf
CC		=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -g3
HEADER		=	-I./include/
MLX_LINK	=	-L minilibx/ -lmlx -lX11 -lXext
MATH_LINK	=	-lm
LIBFT_LINK	=	-I./include/libft/header -L $(LIBFT) -lft
LIBFT		=	./include/libft/

SRCS_GRAPH	=	graphics_init.c graphics_end.c
SRCS_DRAW	=	butterfly.c circle.c cube.c update.c plane.c
SRCS_DRAW	+=	fill.c line.c pixel.c point.c square.c
SRCS_MTX	=	new.c identity.c from_vec.c rotate.c
SRCS_MTX	+=	multiply.c fill.c print.c
SRCS_MTX	+=	null.c nullv.c init.c
SRCS_VEC	=	from_mtx.c new.c center.c isometry.c

SRCS_ALL	=	$(addprefix graphics/,$(SRCS_GRAPH))
SRCS_ALL	+=	$(addprefix graphics/draw_,$(SRCS_DRAW))
SRCS_ALL	+=	$(addprefix matrix/mtx_,$(SRCS_MTX))
SRCS_ALL	+=	$(addprefix matrix/vec_,$(SRCS_VEC))

ANSI		=	\033[0
BOLD		=	;1
YELLOW		=	;33
MAGENTA		=	;35
CYAN		=	;36

TMAIN_MTX	=	tests/mtx_test.c
TMAIN_LERP	=	tests/lerp_test.c
TMAIN_TOOL	=	tests/tool_test.c
TMAIN_FORM	=	tests/formulas_test.c

all: libft $(NAME) formulas

$(NAME): tests

libft: 
	@make -C $(LIBFT)

tests: libft mtx_test lerp_test tool_test

formulas:
	@$(CC) $(C_FLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_FORM) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "formulas" "Compiled"
	@echo
	@printf "%s: $(ANSI)$(MAGENTA)m%.15s$(ANSI)m" " B" "butterfly_curve"
	@printf "%s: $(ANSI)$(MAGENTA)m%.15s$(ANSI)m" "| B" "butterfly_curve"
	@echo

mtx_test:
	@$(CC) $(C_FLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_MTX) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s$(ANSI)m\n" "mtx_test" "Compiled"

lerp_test:
	@$(CC) $(C_FLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_LERP) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s$(ANSI)m\n" "lerp_test" "Compiled"

tool_test:
	@$(CC) $(C_FLAGS) $(SRCS_ALL) $(HEADER) $(TMAIN_TOOL) -o $@ $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s$(ANSI)m\n" "tool_test" "Compiled"

clean:
	@echo
	@rm -rf $(OBJS_DIR)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "Objects" "Cleaned"

clean_tests:
	@rm -rf mtx_test
	@rm -rf lerp_test
	@rm -rf tool_test
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
