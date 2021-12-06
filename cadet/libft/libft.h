#ifndef LIBFT_H
# define  LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

void	ft_bzero(void *s, size_t n);

int		ft_isalpha(int arg);
int		ft_isalnum(int arg);
int		ft_isascii(int number);
int		ft_isdigit(int arg);
int		ft_isprint( int number);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *s, int c);
int		strncmp(const char	*str1, const char	*str2, size_t n);
void	*memchr(const void	*ptr, int value, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *str, const char *substr, size_t n);
int		ft_atoi(const char *str);

#endif