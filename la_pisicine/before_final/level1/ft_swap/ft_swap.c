/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:44:01 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/29 17:46:45 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int a = 5;
	int b = 20;
	printf("%d , %d\n", a, b);
	ft_swap(&a,&b);
	printf("%d , %d\n", a, b);
	return 0;
}