# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 14:44:38 by cmanfred          #+#    #+#              #
#    Updated: 2019/03/06 16:14:59 by cmanfred         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror -Ofast -I includes/
INCLUDES = -I ./libs/libft/ -I ./libs/minilibx/ -I ./libs/graphic_libft/
LIBFLAGS = -L./libs/libft -lft -L./libs/minilibx -lmlx -framework OpenGL \
		   -framework AppKit -L./libs/graphic_libft/ -lgft \
		   -lpthread
FILES = main.c init.c hook.c julia.c additional_func.c mandelbrot.c spider.c \
		burning_ship.c lambda.c drop.c
SRCS = $(addprefix srcs/, $(FILES))
OBJ = $(addprefix objectives/, $(FILES:.c=.o))

all: $(NAME)

$(NAME):$(OBJ) | lib
	@gcc $(FLAGS) $(LIBFLAGS) -o $(NAME) $(OBJ)

objectives/%.o: srcs/%.c | objectives
	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $^

re: fclean all

lib:
	@make -C ./libs/libft
	@make -C ./libs/minilibx
	@make -C ./libs/graphic_libft

clean:
	@rm -rf objectives/
	@make clean -C ./libs/libft
	@make clean -C ./libs/minilibx
	@make clean -C ./libs/graphic_libft

fclean: clean
	@make fclean -C ./libs/graphic_libft
	@make fclean -C ./libs/libft
	@rm -rf $(NAME)

objectives:
	@mkdir objectives/
