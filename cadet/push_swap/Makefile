# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 14:49:18 by hyunjung          #+#    #+#              #
#    Updated: 2022/05/05 14:53:09 by hyunjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PUSH_SWAP

CC		= cc
CFLAG	= -Wall -Wextra -Werror

RM		= rm -f

SRCS	= push_swap.c
OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME):	$(OBJS)

%.o\	: %.c
			$(CC)	$(CFLAG) -c $< -o $@

clean	:
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME)

re : fclean all

	
.PHONY : all clean fclean re