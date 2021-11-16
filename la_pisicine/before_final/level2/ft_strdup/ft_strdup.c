/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:19:39 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/30 20:35:00 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *c)
{
	int i = 0;
	
	while (c[i] != 0)
	{
		i++;
	}
	return i;
}
char    *ft_strdup(char *src)
{
	char *arr;
	int i = 0;
	arr = malloc(ft_strlen(src) * sizeof(char) + 1);

	while (src[i] != 0)
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = 0;
	return arr;
}

int main()
{
	char *arr = "testWorld";
	
	printf("add : %x %s\n", &arr, arr);
	printf(" add : %x %s\n", ft_strdup(&arr), arr);
	
}