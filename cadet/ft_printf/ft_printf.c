/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:14:38 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/23 16:39:04 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_reader(const char **str, va_list ap)
{	
	int	str_length;
	int	i;

	str_length = 0;
	if (**str == 'c')
	{
		i = va_arg(ap, int);
		write(1, &i, 1);
		(*str)++;
		str_length++;
	}
	else if (**str == 's')
		return (ft_print_str(str, ap));
	// else if (**str == 'p')
		
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
	// else //지정된 서식지정자가 아니라면 %a등 그대로 출력하고 length만큼 추가해준다. 그냥 문자열로 취급
	// {
	// 	// write(1, &str, 1);
	// / 	str_length++;	
	// }// 	(*str)++;
	// /
	return (str_length);
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
	printf("origin hex => %x %X\n", -1, 10);
	ft_printf("ft hex => %x %X", -1, 10);
	return (0);
}
