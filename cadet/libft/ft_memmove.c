/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:14:11 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/02 16:39:27 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			idx;

	idx = 0;
	if (dest <= src)
	{
		new_dest = (unsigned char *)dest;
		new_src = (unsigned char *)src;
		while (idx++ < size)
		{
			*new_dest++ = *new_src++;
		}
	}
	else
	{
		new_dest = dest + (size - 1);
		new_src = src + (size - 1);
		while (idx++ < size)
		{
			new_dest[size - 1] = new_src[size - 1];
		}
	}
	return (dest);
}
