# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 15:34:52 by hyunjung          #+#    #+#              #
#    Updated: 2022/04/19 13:39:45 by hyunjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRCS = so_long.c \
 		map.c \
		get_next_line.c \
		get_next_line_utils.c \
		image.c \
		utils.c \
		key.c

OBJS = $(SRCS:%.c=%.o)

CC = clang
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME)	: $(OBJS)
		arch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit so_long.c map.c get_next_line.c get_next_line_utils.c image.c utils.c key.c

%.o: %.c
		arch -x86_64 gcc $(FLAGS) -c $^ -I./ -o $@

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
