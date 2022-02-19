/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:07 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/19 11:33:44 by hyunjung         ###   ########.fr       */
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
	while (tmp[i] != 0)
	{
		write(1, &tmp[i], 1);
		i++;
	}
	return (1);
}

int	ft_print_perc(const char **str)
{
	int		i;
	char	*tmp;

	// 왜 문자가 88로 출력될까 ? 아스키 테이블에서 88은 X이다.
	printf("look at this => %c", **str);
	i = 0;
	(*str)++;
	while (str[i] != 0)
	{
		write(1, *str[i], 1);
		i++;
	}
	return (1);
}
