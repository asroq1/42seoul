/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:38:10 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/19 10:54:39 by hyunjung         ###   ########.fr       */
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
