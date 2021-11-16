/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:45:24 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/23 20:33:13 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	char *new_str;

	new_str = (char *)malloc(sizeof(char) * (sizeof(src) + 1));
	if (*new_str)
	{
		return 0;
	}
	
	while (src[i] != '\0')
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return(new_str);
}

int main()
{
	char t[50] = "test";
	printf("복사한 곳의 주소 : %p \n", ft_strdup(0));
	printf("복사한 곳의 주소 : %p \n", &t);
}