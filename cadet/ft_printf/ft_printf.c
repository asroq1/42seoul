/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:14:38 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/24 17:02:04 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_reader(const char **str, va_list ap)
{	
	int	i;

	if (**str == 'c')
	{
		i = va_arg(ap, int);
		write(1, &i, 1);
		(*str)++;
		return (1);
	}
	else if (**str == 's')
		return (ft_print_str(str, ap));
	else if (**str == 'p')
		return (ft_printf_addr(str, ap));
	else if (**str == 'd' || **str == 'i')
		return (ft_print_num(str, ap));
	else if (**str == 'u')
		return (ft_print_dec(str, ap));
	else if (**str == 'x')
		return (ft_print_hex(str, ap));
	else if (**str == 'X')
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

// int main(void)
// {
// 	printf("ORIGIN %x %X\n", 0, 0);
// 	ft_printf("FT %x %X", 0 , 0);

// }