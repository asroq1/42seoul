/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:20:12 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/23 23:42:08 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	unsigned long power = 1;
	while (power < n)
	{
		power = 2 * power;
	}
	if (power == n)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int main()
{
	printf("%d", is_power_of_2(8));
	
}