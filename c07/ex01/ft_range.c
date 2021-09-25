/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 23:43:11 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/25 13:20:55 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	new_arr;
	int	size;
	int	i;

	i = 0;
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
}
