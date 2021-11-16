/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:38:53 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/30 21:23:28 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != 0)
	{
		i++;
	}
	return i;
}

char    *ft_strrev(char *str)
{
	int i = 0;
	int start = 0;
	int end = ft_strlen(str) - 1;
	char tmp;
	int size = ft_strlen(str);
	
	while (i < size/ 2)
	{ 
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
		i++; 
	}
	return(str);
}

int main()
{
	char test[50] = "HELLO";
	printf("%s",ft_strrev(test)); 
}