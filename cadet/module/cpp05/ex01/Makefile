NAME		= a.out

CC			= c++
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra -std=c++98

HEADER		= ./
SRCS_DIR	= ./
SRCS		= main.cpp \
			  Bureaucrat.cpp \
			  Form.cpp \

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