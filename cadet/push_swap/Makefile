# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 14:49:18 by hyunjung          #+#    #+#              #
#    Updated: 2022/06/13 18:02:58 by hyunjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
LIBFT	=	libft
LIBFT_A	=	libft.a

CC		= cc
CFLAG	= -Wall -Wextra -Werror

RM		= rm -f

SRCS	= push_swap.c \
		  validater.c

OBJS	= $(SRCS:.c=.o)
LIBC	= ar rc

all : $(NAME)

$(NAME):	$(OBJS)
			make all -C $(LIBFT)/
			gcc	-o $(NAME) $(OBJS) -Llibft	-lft

%.o\	: %.c
			$(CC)	$(CFLAG) -c $^	-I./ -o $@

clean	:
		$(RM) -f $(OBJS)
		make clean -C $(LIBFT)

fclean	: clean
		$(RM) -f $(NAME)
		$(RM) -f $(LIBFT_A)
		make fclean -C $(LIBFT)

re : fclean all

	
.PHONY : all clean fclean re bonus