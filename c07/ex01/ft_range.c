/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 23:43:11 by hyunjung          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/09/26 13:10:54 by hyunjung         ###   ########.fr       */
=======
/*   Updated: 2021/09/25 13:20:55 by hyunjung         ###   ########.fr       */
>>>>>>> 0fcd5bfb7b0a0f0d32a21325955e0092e1c9b8bd
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
<<<<<<< HEAD
	int	*new_arr;
=======
	int	new_arr;
	int	size;
>>>>>>> 0fcd5bfb7b0a0f0d32a21325955e0092e1c9b8bd
	int	i;

	if (min > max)
	{
		return (0);
	}
	i = 0;
<<<<<<< HEAD
	new_arr = malloc(sizeof(int) * (max - min));
	if (new_arr == 0)
	{
		return (0);
	}
	while (max > min)
	{
		new_arr[i] += min;
		min++;
		i++;
	}
	return (new_arr);
=======
	size = (max - min) + 1;
	new_arr = malloc(sizeof(int) * size);
	printf("arr leng : %lu", new_arr); 

	printf("arr leng : %lu", sizeof(new_arr)); 
	// while (new_arr)
	// {
	// 	new_arr = min;
	// 	new_arr++;
	// 	i++;
	// }
	// return (new_arr);
>>>>>>> 0fcd5bfb7b0a0f0d32a21325955e0092e1c9b8bd
}
