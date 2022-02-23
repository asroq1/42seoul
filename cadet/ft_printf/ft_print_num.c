/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:38:10 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/23 11:41:41 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(const char **str, va_list ap)
{
	int		i;
	int		n;
	int		str_length;
	char	*tmp;

	i = 0;
	str_length = 0;
	n = va_arg(ap, int);
	tmp = ft_itoa(n);
	while (tmp[i] != 0)
	{
		write(1, &tmp[i], 1);
		i++;
	}
	str_length = ft_strlen(tmp);
	(*str)++;
	return (str_length);
}

int	ft_print_dec(const char **str, va_list ap)
{
	int					i;
	unsigned int		n;
	int					str_length;
	char				*tmp;

	i = 0;
	str_length = 0;
	n = va_arg(ap, unsigned int);
	tmp = ft_dtoa(n);
	while (tmp[i] != 0)
	{
		write(1, &tmp[i], 1);
		i++;
	}
	str_length = ft_strlen(tmp);
	(*str)++;
	return (str_length);
}

char	*ft_dtoa(unsigned int n)
{
	long	value;
	size_t	length;
	char	*new_str;

	length = ft_unsinged_length(n);
	value = n;
	new_str = malloc(length * sizeof(char) + 1);
	if (new_str == 0)
		return (0);
	if (value < 0)
	{
		new_str[0] = '-';
		value *= -1;
	}
	if (value == 0)
		new_str[0] = '0';
	new_str[length] = 0;
	length -= 1;
	while (value != 0)
	{
		new_str[length] = '0' + value % 10;
		length--;
		value /= 10;
	}
	return (new_str);
}

size_t	ft_unsinged_length(unsigned int n)
{
	size_t	length;

	if (n == 0)
	{
		return (1);
	}
	length = 0;
	if (n < 0)
	{
		length++;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}
