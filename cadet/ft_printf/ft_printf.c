/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:14:38 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/24 13:01:23 by hyunjung         ###   ########.fr       */
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

int	main(void)
{
	size_t i;
	// i = 7;
	//char string tester
	// ft_printf("my eng is %c %c %c %s", 'A', 'B', 'C', "alphabet");
	
	// numbers tester
	// ft_printf("%d %d %d", 100, 200, 300);
	
	// percent tester
	// ft_printf("my => %% %%%% %%%");

	// decimal tester
	// printf("origin => %u\n", -4294967295);
	// ft_printf("my => %u", -4294967295);
	
	// hexadecimal tester
	// printf("origin hex => %x %X\n", -2, 2015);
	// ft_printf("ft hex => %x %X", -2, 2015);\

	// address tester
	printf("oirign addr => %p\n", i);
	ft_printf("ft addr => %p", i);
	return (0);
}
