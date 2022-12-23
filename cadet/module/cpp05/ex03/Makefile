# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2022/11/22 16:26:18 by hyunjung          #+#    #+#              #
# #    Updated: 2022/12/23 17:04:24 by hyunjung         ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

# SRCS = ./main.cpp  \
# 	   ./Bureaucrat.cpp \
# 	   ./AForm.cpp \
# 	   ./Intern.cpp \
# 	   ./ShrubberyCreationForm.cpp \
# 	   ./RobotomyRequestForm.cpp \
# 	   ./PresidentialPardonForm.cpp \
# CXX = c++
# NAME = a.out

# CXXFLAGS = -Wall -Wextra -Werror -std=c++98
# OBJS = $(SRCS:.cpp=.o)


# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re

NAME		= a.out

CC			= c++
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra -std=c++98

HEADER		= ./
SRCS_DIR	= ./
SRCS		= main.cpp \
			  Bureaucrat.cpp \
			  AForm.cpp \
			  ShrubberyCreationForm.cpp \
			  RobotomyRequestForm.cpp \
			  PresidentialPardonForm.cpp \
			  Intern.cpp

ALLSRCS	= $(addprefix $(SRCS_DIR), $(SRCS))
OBJS	= $(ALLSRCS:.cpp=.o)

all	: $(NAME)

%.o		: %.cpp
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY  :	all clean fclean re