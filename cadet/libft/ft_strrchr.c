/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:04:02 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/09 19:25:41 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	length;

	length = strlen(str);
	if (c == 0)
	{
		return ((char *)&str[length]);
	}
	while (length != 0)
	{
		if (str[length - 1] == (unsigned char)c)
		{
			return ((char *)&str[length - 1]);
		}
		length--;
	}
	return (0);
}
