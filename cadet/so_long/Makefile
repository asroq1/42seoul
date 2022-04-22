# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 15:34:52 by hyunjung          #+#    #+#              #
#    Updated: 2022/04/22 16:48:09 by hyunjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c \
 		map.c \
		get_next_line.c \
		get_next_line_utils.c \
		utils.c \
		key.c \
		error.c

OBJS = $(SRCS:%.c=%.o)

CC = clang
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME)	: $(OBJS)
			gcc -o $(NAME) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o: %.c
		gcc $(FLAGS) -c $^ -I./ -o $@

clean :
	rm -rf $(OBJS)

fclean :	clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
