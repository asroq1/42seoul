/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:41:11 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/24 10:53:59 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int main(int argc, char **arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc < 2)
	{
		return 0;
	}
	
		while (arr[2][i] != '\0')
		{
			if (arr[2][i] == arr[1][j])
			{
				j++;
			}
			i++;
		}
		if (arr[1][j] == '\0' && arr[2][i] == '\0')
		{
			write(1, &arr[2][i], 1);
		}
		
		write(1, "\n", 1);
	
}