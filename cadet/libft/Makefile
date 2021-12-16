# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 17:35:28 by hyunjung          #+#    #+#              #
#    Updated: 2021/12/16 17:49:55 by hyunjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -I.
CC = gcc
SRCS = ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isalnum.c \
            ft_tolower.c ft_toupper.c \
            ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c \
            ft_strlen.c ft_strlcpy.c ft_strdup.c ft_strncmp.c ft_strnstr.c \
            ft_strrchr.c ft_strlcat.c ft_strchr.c \
            ft_calloc.c ft_bzero.c ft_atoi.c ft_itoa.c ft_strtrim.c \
            ft_substr.c ft_strjoin.c ft_atoi.c ft_strmapi.c  \
            ft_putchar_fd.c ft_split.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
            ft_striteri.c
SRCS_B = ft_lstnew.c ft_lstsize.c ft_lstlast.c \
            ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c \
            ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECTS = $(SRCS:%.c=%.o)

OBJECTS_B = $(SRCS_B:%.c=%.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJECTS) $(OBJECTS_B)
else
	OBJ_FILES = $(OBJECTS)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
		ar rcs $(NAME) $(OBJECTS)

bonus : 
	make WITH_BONUS=1 all
clean : 
	rm -f $(OBJECTS) $(OBJECTS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re