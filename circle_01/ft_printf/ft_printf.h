/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:14:51 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/15 14:24:14 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_printf(const char *str, ...);
int				ft_str_reader(const char **str, va_list ap);
int				ft_printf_char(const char **str, va_list ap);
int				ft_print_str(const char **str, va_list ap);
int				ft_print_perc(const char **str);
int				ft_print_num(const char **str, va_list ap);
int				ft_print_dec(const char **str, va_list ap);
int				ft_print_hex(const char **str, va_list ap);
int				ft_printf_addr(const char **str, va_list ap);
void			ft_putchar(char c);
void			ft_putnbr(int n);
char			*ft_itoa(int n);
char			*ft_dtoa(unsigned int n);
size_t			ft_int_length(int n);
size_t			ft_unsinged_length(unsigned int n);
size_t			ft_strlen(const char *str);
int				ft_putnbr_base(unsigned int n, char *base);
int				ft_putnbr_addr(size_t n, char *base);

#endif
