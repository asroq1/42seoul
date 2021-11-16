/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscpn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:48:26 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/30 20:18:59 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int j = 0;
	int cnt = 0;
	while (s[i] != 0)
	{
		j = 0;
		while (reject[j] != 0)
		{
			if (s[i] == reject[j])
			{
				return i;
			}
			j++;
		}
		i++;
	}
	return i;	
}
int main()
{
	char *str = "as@gmai.com";
	char *str2 = "!@?";

	printf("mine :%ld\n", ft_strcspn(str , str2));	
	printf("origin :%ld\n", strcspn(str , str2));	
}