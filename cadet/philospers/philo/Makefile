# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 17:52:50 by hyunjung          #+#    #+#              #
#    Updated: 2022/07/25 19:59:31 by hyunjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	main.c \
		init.c \
		utils.c \
		philo.c \
		thread.c \

OBJS = $(SRCS:%.c=%.o)

FLAGS	= -Wall -Wextra -Werror 

all	: $(NAME)

$(NAME)	:	$(OBJS)
		cc $(FLAGS)  -o $(NAME) $(OBJS)

%.o	:	%.c
	cc $(FLAGS) -c $^ -I./

clean	: 
		rm -f $(OBJS)

fclean	: 	clean
		rm -f $(NAME)

re : fclean all

.PHONY	: all clean fclean re bonus