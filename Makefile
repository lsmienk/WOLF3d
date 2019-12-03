# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ihering- <ihering-@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/16 10:20:01 by ihering-       #+#    #+#                 #
#    Updated: 2019/11/27 13:58:35 by lsmienk       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = main read_maze create_walls wolfloop d_draw plotpoint draw_line \
	key_controls raycasting intersection line_distance bcolour calc_wall \
	render_wall calc_pix draw_circle collision
SRCF = $(SRC:%=srcs/%.c)
OBJ = $(SRC:%=%.o)
NAME = wolf3d
MINILIBX = -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
LIBFT = -I libft/includes -L libft -lft
FLAGS = -Wall -Werror -Wextra

MAKECOLOUR = \033[38;5;208m
CLEANCOLOUR = \033[38;5;229m
FCLEANCOLOUR = \033[38;5;214m
LIBCOLOUR = \033[38;5;220m
RESETCOLOUR = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCF)
	@echo "$(LIBCOLOUR)Compiling Libraries$(RESETCOLOUR)"
	@make -C libft/
	@make -C minilibx/
	@echo "$(MAKECOLOUR)Compiling Program$(RESETCOLOUR)"
	@clang -g $(FLAGS) -I minilibx -I libft/includes -c $(SRCF)
	@clang -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX)

clean:
	@echo "$(CLEANCOLOUR)Cleaning Libraries$(RESETCOLOUR)"
	@make -C libft/ clean
	@make -C minilibx/ clean
	@rm -f $(OBJ)

fclean: clean
	@echo "$(FCLEANCOLOUR)Removing Libraries and $(NAME) $(RESETCOLOUR)"
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
