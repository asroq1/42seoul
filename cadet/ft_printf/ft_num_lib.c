/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:50:02 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/23 16:03:15 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	long	value;
	size_t	length;
	char	*new_str;

	length = ft_int_length(n);
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

size_t	ft_int_length(int n)
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
