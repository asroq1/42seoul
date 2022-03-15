/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:14:38 by hyunjung          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/15 14:06:27 by hyunjung         ###   ########.fr       */
=======
/*   Updated: 2022/03/03 11:52:55 by hyunjung         ###   ########.fr       */
>>>>>>> d9264f883129591b975c62029c4693393528c160
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_reader(const char **str, va_list ap)
{	
	if (**str == 'c')
		return (ft_printf_char(str, ap));
	else if (**str == 's')
		return (ft_print_str(str, ap));
	else if (**str == 'p')
		return (ft_printf_addr(str, ap));
	else if (**str == 'd' || **str == 'i')
		return (ft_print_num(str, ap));
	else if (**str == 'u')
		return (ft_print_dec(str, ap));
	else if (**str == 'x' || **str == 'X')
		return (ft_print_hex(str, ap));
	else if (**str == '%')
		return (ft_print_perc(str));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		str_length;
	va_list	ap;

	str_length = 0;
	va_start(ap, str);
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			str_length += ft_str_reader(&str, ap);
		}
		else
		{
			write(1, str++, 1);
			str_length++;
		}
	}
	va_end(ap);
	return (str_length);
}
