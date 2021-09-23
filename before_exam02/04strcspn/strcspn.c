/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcspn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:12:40 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/23 19:42:34 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int j = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
			{
				return i;
			}
				j++;
		}
		i++;
	}
	return 100;
}

int  main()
{
	char *str = "asroq9@8.gmail.com";
	char *strchar = "!@.";
	printf("%d", ft_strcspn(str, strchar));
}

