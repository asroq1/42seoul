/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:07 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/16 16:20:37 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char **str, va_list ap)
{
	int		length;
	char	*temp;

	length = 0;
	temp = va_arg(ap, char *);
	while (*temp != 0)
	{
		write(1, temp++, 1);
		length++;
	}
	return (length);
}
