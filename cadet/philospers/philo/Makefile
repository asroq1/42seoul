# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 17:52:50 by hyunjung          #+#    #+#              #
#    Updated: 2022/07/08 18:27:18 by hyunjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	main.c \

OBJS = $(SRCS:%.c=%.o)

LIBC = ar rc

FLAGS	= -Wall -Wextra -Werror

all	: $(NAME)

$(NAME)	:	$(OBJS)
		gcc -o $(NAME) $(OBJS)

%.o	:	%.c
	cc $(FLAGS) -c $^ -I./	-o $@

clean	: rm -f $(OBJS)

fclean	: clean
			rm -f (NAME)
re : fclean all

.PHONY	: all clean fclean re bonus