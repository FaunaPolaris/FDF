NAME		=	conway
CC		=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -g3
HEADER		=	-I./include/
MLX_LINK	=	-L minilibx/ -lmlx -lX11 -lXext
MATH_LINK	=	-lm
LIBFT_LINK	=	-I./include/libft/header -L $(LIBFT) -lft
LIBFT		=	./include/libft/

SRCS_GRAPH	=	win_new.c
SRCS_DRAW	=	butterfly.c circle.c cube.c update.c plane.c
SRCS_DRAW	+=	fill.c line.c pixel.c point.c square.c
SRCS_PERLIN	=	nowl.c
SRCS_MTX	=	new.c identity.c from_vec.c rotate.c
SRCS_MTX	+=	multiply.c fill.c print.c
SRCS_MTX	+=	null.c nullv.c init.c
SRCS_VEC	=	from_mtx.c new.c center.c isometry.c

SRCS_ALL	=	$(addprefix graphics/,$(SRCS_GRAPH))
SRCS_ALL	+=	$(addprefix graphics/perlin_,$(SRCS_PERLIN))
SRCS_ALL	+=	$(addprefix graphics/draw_,$(SRCS_DRAW))
SRCS_ALL	+=	$(addprefix matrix/mtx_,$(SRCS_MTX))
SRCS_ALL	+=	$(addprefix matrix/vec_,$(SRCS_VEC))

ANSI		=	\033[0
BOLD		=	;1
YELLOW		=	;33
MAGENTA		=	;35
CYAN		=	;36

CON_MAIN	=	programs/conway.c
PERLIN_MAIN	=	programs/perlin.c

all: libft $(NAME)

$(NAME):
	@$(CC) $(C_FLAGS) $(HEADER) $(CON_MAIN) -o $(NAME) $(SRCS_ALL) $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "conway" "Compiled"

perlin:
	@$(CC) $(C_FLAGS) $(HEADER) $(PERLIN_MAIN) -o $@ $(SRCS_ALL) $(MLX_LINK) $(MATH_LINK) $(LIBFT_LINK)
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "perlin" "Compiled"

libft: 
	@make -C $(LIBFT)

clean:
	@rm -rf *.o
	@rm -rf $(NAME)
	@rm -rf perlin
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "Objects" "Cleaned"
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "Executables" "Cleaned"

fclean: clean clean_tests
	@make -C $(LIBFT) fclean
	@printf "%-30s$(ANSI)$(YELLOW)$(BOLD)m%s;$(ANSI)m\n" "libraries" "Cleaned"
	@echo


re: fclean all

.PHONY: all libft clean fclean re 
