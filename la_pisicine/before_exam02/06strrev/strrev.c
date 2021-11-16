/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:50:11 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/23 21:21:40 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int cnt = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
		cnt++;
	}
	return (cnt);
}
char    *ft_strrev(char *str)
{
	int i = 0;
	int size = ft_strlen(str);
	int start = 0;
	int end = size - 1;
	char temp;
printf("OK\n");
	while (i < size / 2)
	{
		printf("%d\n" ,i);
		printf("%d\n" ,end);
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		i++;
		start++;
		end--;
	}
	// str[i] = '\0';

	return(str);
}

int main()
{
	char t[10] = "hello";
	printf("%s",ft_strrev(t));
}