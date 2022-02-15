/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:14:38 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/15 15:06:26 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_str_reader(char c, va_list ap)
{
	if (c == 'c')
	{
		//함수로 쪼개서 만들기.
		char	a;
		a = va_arg(ap, int);
		write(1, &a, 1);
	}
	// 이후 다른 조건문도 추가
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		str_length;
	va_list	ap;

	str_length = 0;
	va_start(ap, (int)str);
	while (*str != 0)
	{
		if (*str == '%')
		{
			ft_str_reader(*(++str), ap);
			str++;
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
	ft_printf("my grade is %c", 'A');
	 return (0);
}
