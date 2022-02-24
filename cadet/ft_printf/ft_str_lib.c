/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:53:43 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/24 12:52:40 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int n, char *base)
{
	int	i;
	int	base_length;
	int	nbr_box[256];

	i = 0;
	base_length = 0;
	while (base[base_length] != 0)
	{
		base_length++;
	}
	while (n != 0)
	{
		nbr_box[i] = n % base_length;
		n = n / base_length;
		i++;
	}
	while (--i >= 0)
	{
		ft_putchar(base[nbr_box[i]]);
	}
}

void	ft_putnbr_addr(size_t n, char *base)
{
	int	i;
	int	base_length;
	int	nbr_box[256];

	i = 0;
	base_length = 0;
	while (base[base_length] != 0)
	{
		base_length++;
	}
	while (n != 0)
	{
		nbr_box[i] = n % base_length;
		n = n / base_length;
		i++;
	}
	while (--i >= 0)
	{
		ft_putchar(base[nbr_box[i]]);
	}
}
