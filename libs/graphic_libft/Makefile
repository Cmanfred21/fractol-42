# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 15:36:29 by cmanfred          #+#    #+#              #
#    Updated: 2019/02/26 18:10:34 by cmanfred         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgft.a
INCLUDES = -I ../../minilibx/ -I ../libft/
LIB = -L../libft/ -lft -L../../minilibx/ -lmlx
FLAGS = -Wall -Wextra -Werror
FILES 		= image_operations.c

OFILES = $(addprefix objectives/, $(FILES:%.c=%.o))

all: $(NAME)

$(NAME): $(OFILES)
	ar -rc $(NAME) $(OFILES)

objectives/%.o: ./%.c | objectives
	gcc $(FLAGS) $(INCLUDES) -o $@ -c $^

objectives:
	mkdir objectives/

clean:
	rm -rf objectives/

fclean: clean
	rm -rf $(NAME)

re: fclean all
