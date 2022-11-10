NAME	= test

CPP =  c++
RM = rm -rf
CPPFLAGS = -Werror -Wall -Wextra -std=c++98

HEADER = ./
SRCS_DIR = ./
SRCS = Contact.cpp main.cpp PhoneBook.cpp

ALLSRCS = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(ALLSRCS:.cpp=.o)

all : $(NAME)

%.o	:	%.cpp
	$(CC) $(CPPFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME) : $(OBJS)
		$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	
clean : 
		$(RM) $(OBJS)
	
fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re