/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:03:12 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/29 17:06:46 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int main()
{
	char t[50] = "test,,";
	printf("ans : %d", ft_strlen(t));
	return 0;
}