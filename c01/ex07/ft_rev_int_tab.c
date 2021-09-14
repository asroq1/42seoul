/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:01:07 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/14 16:09:40 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	back;
	int	front;
	int	temp;
	int	cnt;

	front = 0;
	back = size - 1;
	cnt = 0;
	while (cnt < size / 2)
	{
		temp = tab[front];
		tab[front] = tab[back];
		tab[back] = temp;
		front++;
		back--;
		cnt++;
	}
}
