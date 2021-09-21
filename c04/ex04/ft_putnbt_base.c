/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbt_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:30:12 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/21 21:44:14 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthcar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		str++;
		cnt++;
	}
	return (cnt);
}

int	is_this_duplicate(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
		{
			return (1);
		}
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr(long nbr, int base_length, char *base_arr)
{
	if (nbr < base_length && nbr >= 0)
	{	
		ft_puthcar(base_arr[nbr % base_length]);
	}
	else if (nbr < 0 && nbr != -2147483648)
	{
		ft_puthcar('-');
		ft_putnbr(nbr * (-1), base_length, base_arr);
	}
	else
	{
		ft_putnbr(nbr / base_length, base_length, base_arr);
		ft_putnbr(nbr % base_length, base_length, base_arr);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;

	base_length = ft_strlen(base);
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1 || is_this_duplicate(base))
	{
		return ;
	}
	base_length = ft_strlen(base);
	ft_putnbr((long)nbr, base_length, base);
	return ;
}
