/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:55:03 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/24 10:27:50 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char *cutter(char *c)
{
	int i;
	int j;
	int k = 0;
	int cnt;
	char arr[1000];
	while (c[i] != '\0')
	{
		j = i + 1;
		while (c[j] != '\0')
		{
			if (c[i] == c[j])
			{
				cnt++;
			}
			j++;
		}
		if (cnt == 1)
		{
			arr[k] += c[i];
			k++;
		}	
		i++;
	}
	return (arr);
}
int main(int argc, char **arr)
{
	int i = 0;
	int j;
	int cnt;
	
	if (argc != 2)
	{
		write(1, "\n", 1);
	}
	cutter(arr[1]);
	while (arr[1][i] != '\0')
	{
			j = 0;
		while (arr[2][j] != '\0')
		{
			cnt = 0;
			if (arr[1][i] == arr[2][j])
			{
				cnt++;
			}	
			j++;		
			if (cnt == 1)
			{
				write(1, &arr[1][i], 1);
				break;
			}
		}
		i++;
	}
	
}