# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 13:11:49 by devicii           #+#    #+#              #
#    Updated: 2022/02/24 13:05:08 by hyunjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_printf.c \
		ft_printf_tool.c \
		ft_print_num.c \
		ft_print_str.c \
		ft_print_hex.c \
		ft_nun_lib.c \
		ft_str_lib.c

FLAGS = -c -Wall -Wextra -Werror
AR_FLAGS = -rcs
INCLUDE = -I./include

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar $(AR_FLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
