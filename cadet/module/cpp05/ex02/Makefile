# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 16:26:18 by hyunjung          #+#    #+#              #
#    Updated: 2022/12/23 13:57:56 by hyunjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./main.cpp  \
	   ./Bureaucrat.cpp \
	   ./AForm.cpp \
	   ./ShrubberyCreationForm.cpp \
	   ./RobotomyRequestForm.cpp \
	   ./PresidentialPardonForm.cpp \
	   
CXX = c++
NAME = a.out

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re