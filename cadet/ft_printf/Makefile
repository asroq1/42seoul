# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 13:11:49 by hyunjung           #+#    #+#              #
#    Updated: 2022/03/01 17:07:59 by hyunjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
CFLAG	    = -Wall -Wextra -Werror

RM			= rm -f

AR			= ar
ARFLAGS     = crs

SRCS		= ft_printf.c ft_printf_tool.c ft_num_lib.c ft_printf_hex.c ft_printf_str.c ft_printf_num.c	

OBJS		= $(SRCS:.c=.o)

all : $(NAME)

${NAME}:	${OBJS}
		${AR} ${ARFLAGS} ${NAME} ${OBJS}

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

 .PHONY : all clean fclean re