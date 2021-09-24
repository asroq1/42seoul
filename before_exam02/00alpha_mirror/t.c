/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:43:01 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/24 10:53:23 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int cnt, char **arr)
{
	int i = 0;
	if (cnt != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	
	while (arr[1][i] != '\0')
	{
		if (arr[1][i] >= 'A' && arr[1][i] <= 'Z')
		{
			arr[1][i] = 'M' - (arr[1][i] - 'N');
			write(1, &arr[1][i], 1);
		}
		else if (arr[1][i] >= 'a' && arr[1][i] <= 'z')
		{
			arr[1][i] = 'm' - (arr[1][i] - 'n');
			write(1, &arr[1][i], 1);
		}
		else if(!(arr[1][i] >= 'A' && arr[1][i] <= 'Z' && arr[1][i] >= 'a' && arr[1][i] <= 'z'))
		{
			write(1, &arr[1][i], 1);
		}
		else{

			write(1, " ", 1);
		}
		i++;
	}
	
}