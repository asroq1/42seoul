/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:31:59 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/30 19:40:20 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{

	int i = 0;
	int j = 0;
	while (s1[i] != 0)
	{
		while (s2[j] != 0)
		{
			if (s1[i] == s2[j])
			{
				return s1[i];
			}
			j++;
		}
	i++;
	}
	return 0;
}

int main()
{
	char t[20] = "tet";
	char t1[20] = "t";
	printf("mine : %s\n", ft_strpbrk("test", "s"));
	printf("ori : %s\n", strpbrk("test", "s"));
}