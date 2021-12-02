#ifndef LIBFT_H
# define  LIBFT_H

# include <string.h>
# include <unistd.h>

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

#endif