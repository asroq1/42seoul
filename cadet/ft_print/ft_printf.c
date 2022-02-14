/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:14:38 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/14 18:10:33 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

// int	ft_str_reader()
// {
	
// }

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
			printf("!");
			str++;
		}
		else
		{
			write(1, str++, 1);
			printf("str_length = %d\n", str_length);
			str_length++;
		}
	}
	va_end(ap);
	return (str_length);
}

int	main(void)
{
	int	test;

	test = ft_printf("1\n");

	// ft_printf("1");
	printf("res => %d\n", test);
	 return (0);
}
