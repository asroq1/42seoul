# NAME        :=  libft.a
# SRC         :=  ft_memset.c ft_bzero.c ft_memcpy.c \
#                ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
#                ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
#                ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
#                ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
#                ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
#                ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
#                ft_putchar_fd.c ft_putstr_fd.c \
#                ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c
# OBJ         :=  $(SRC:.c=.o)
# BSRC        :=  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
#                ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
#                ft_lstmap.c
# BOBJ        :=  $(BSRC:.c=.o)
# CFLAGS      :=  -Wall -Wextra -Werror
# ifdef WITH_BONUS
#    OBJECTS = $(OBJ) $(BOBJ)
# else
#    OBJECTS = $(OBJ)
# endif
# .PHONY:     all bonus clean fclean re
# all:        $(NAME)
# $(NAME):    $(OBJECTS)
# 	ar -rc $@ $^
# bonus:
#    @make WITH_BONUS=1 all
# *.o:        *.c
# 	$(CC) $(CFLAGS) -c $< -o $@
# clean:
# 	@rm -f $(OBJ) $(BOBJ)
# fclean:     clean
# 	@rm -f $(NAME)
# re:         fclean all


NAME    = libft.a
SRCS    = ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isalnum.c \
            ft_tolower.c ft_toupper.c \
            ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c \
            ft_strlen.c ft_strlcpy.c ft_strdup.c ft_strncmp.c ft_strnstr.c \
            ft_strrchr.c ft_strlcat.c ft_strchr.c \
            ft_calloc.c ft_bzero.c ft_atoi.c ft_itoa.c ft_strtrim.c \
            ft_substr.c ft_strjoin.c ft_atoi.c ft_strmapi.c  \
            ft_putchar_fd.c ft_split.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
            ft_striteri.c
SRCS_BN = ft_lstnew.c ft_lstsize.c ft_lstlast.c \
            ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c \
            ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS    = ${SRCS:.c=.o}
OBJS_BN = ${SRCS_BN:.c=.o}
INCS    = includes
LIBC    = ar rc
LIBR    = ranlib
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror
.c.o:
	${CC}   ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}
${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}
bonus: ${OBJS} ${OBJS_BN}
	${LIBC} $(NAME) ${OBJS} ${OBJS_BN}
	${LIBR} ${NAME}
all: ${NAME}
clean:
	${RM} ${OBJS} ${OBJS_BN}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re .c.o