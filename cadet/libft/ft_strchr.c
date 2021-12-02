/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:29:21 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/02 19:05:54 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != 0)
	{
		if (str[idx] == c)
		{
			return ((char *)&str[idx]);
		}
		idx++;
	}
	return (0);
}
