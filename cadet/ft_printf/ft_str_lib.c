/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:53:43 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/24 16:57:08 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int n, char *base)
{
	int	i;
	int	base_length;
	int	str_length;
	int	nbr_box[256];

	i = 0;
	str_length = 0;
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
		str_length++;
	}
	return (str_length);
}

int	ft_putnbr_addr(size_t n, char *base)
{
	int	i;
	int	str_length;
	int	base_length;
	int	nbr_box[256];

	i = 0;
	str_length = 0;
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
		str_length++;
	}
	return (str_length);
}
