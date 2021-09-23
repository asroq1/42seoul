/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:34:38 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/23 11:59:47 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_is_prime(int nb)
{
	int cnt;
	int i;
	
	i = 2;
	cnt = 0;
	while (i < nb)
	{
		if (nb % i == 0)
		{
			return 0;
		}
		i++;
	}
	return 1;
	
	return ft_is_prime(nb - 1);
}

int main()
{
	printf("%d", ft_is_prime(1));
}