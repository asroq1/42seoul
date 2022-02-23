/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:53:43 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/23 16:50:26 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int n, char *base)
{
	int	i;
	int	size_base;
	int	nbox[100];

	i = 0;
	size_base = 0;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	while (base[size_base] != 0)
	{
		size_base++;
	}
	while (n != 0)
	{
		nbox[i] = n % size_base;
		n = n / size_base;
		i++;
	}
	while (--i >= 0)
	{
		printf("nbox[%d]\n", nbox[i]);
		ft_putchar(base[nbox[i]]);
	}
}
