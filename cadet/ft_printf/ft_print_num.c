/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:38:10 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/19 10:44:05 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 어떻게 제대로 받아온 정수를 가변인자로 잘 출력할 수 있을지에 대해서 생각해보자
// 정수를 어떻게 문자로 출력할 수 있을까
int	ft_print_num(const char **str, va_list ap)
{
	int		i;
	int		n;
	char	*tmp;

	i = 0;
	n = va_arg(ap, int);
	tmp = ft_itoa(n);
	while (tmp[i] != 0)
	{
		write(1, &tmp[i], 1);
		i++;
	}
	(*str)++;
}
