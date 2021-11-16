/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:31:21 by hyunjung          #+#    #+#             */
/*   Updated: 2021/11/16 17:32:12 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i] != 0)
	{
		cnt++;
		i++;
	}
	return (cnt);
}
