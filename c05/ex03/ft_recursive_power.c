/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 23:20:42 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/21 23:53:56 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_recursive_power(int nb, int power)
{ 
	if (power == 0)
	{	
		return 1;
	}
	power--;
	return nb * ft_recursive_power(nb, power);
	
}

int main()
{ 
	printf("%d", ft_recursive_power(2, 4)); 
}