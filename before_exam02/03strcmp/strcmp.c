/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:50:14 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/23 18:58:53 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return(s1[i] - s2[i]);
		}
		i++;
	}
	return(s1[i] - s2[i]);
}

int main()
{
	printf("%d",	ft_strcmp("aaa", "aaa"));
}