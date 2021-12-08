/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:04:02 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/08 11:21:04 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	length;
	size_t	idx;

	length = strlen(str) - 1;
	while (length != 0)
	{
		if (str[length] == c)
		{
			return ((char *)&str[length]);
		}
		else if (str[0] == c)
		{
			return ((char *)&str[0]);
		}
		length--;
	}
	return (0);
}
