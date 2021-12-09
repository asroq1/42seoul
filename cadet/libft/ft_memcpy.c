/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:27:10 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/09 17:37:30 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			idx;

	new_dest = dest;
	new_src = (unsigned char *)src;
	idx = 0;
	while (idx < size)
	{
		new_dest[idx] = new_src[idx];
		idx++;
	}
	return (dest);
}
