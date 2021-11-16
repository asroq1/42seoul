/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:48:30 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/29 17:01:22 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int i = 0;

	while (s2[i] != 0)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}

int main()
{
	char t[50] = "";
	char t1[50] = "AAAAACCCCBBBB";

	
	printf("t :%s\n", t);
	printf("t1 :%s\n",ft_strcpy(t, t1));
	printf("ans :%s\n", t);

}