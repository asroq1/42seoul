SRCS = ./main.cpp  \
	   ./PmergeMe.cpp \
	

CXX = c++
NAME = PmergeMe

CXXFLAGS = 
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