/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:07 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/15 14:22:14 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char **str, va_list ap)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = va_arg(ap, char *);
	(*str)++;
	if (tmp == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (tmp[i] != 0)
	{
		write(1, &tmp[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_perc(const char **str)
{
	write(1, "%", 1);
	(*str)++;
	return (1);
}

int	ft_printf_char(const char **str, va_list ap)
{
	int	i;

	i = va_arg(ap, int);
	write(1, &i, 1);
	(*str)++;
	return (1);
}
