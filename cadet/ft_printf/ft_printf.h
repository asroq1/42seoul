/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:14:51 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/19 11:21:36 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_str_reader(const char **str, va_list ap);
int		ft_print_str(const char **str, va_list ap);
int	ft_print_perc(const char **str);
int		ft_print_num(const char **str, va_list ap);
void	ft_putchar(char c);
void	ft_putnbr(int n);
char	*ft_itoa(int n);
size_t	ft_int_length(int n);
size_t	ft_strlen(const char *str);

#endif
