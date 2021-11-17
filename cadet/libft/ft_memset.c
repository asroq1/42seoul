/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:55:57 by hyunjung          #+#    #+#             */
/*   Updated: 2021/11/17 18:01:16 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			idx;
	unsigned char	*mem;

	idx = 0;
	mem = (unsigned char *)b;
	while (len != 0)
	{
		mem[idx] = c;
		idx++;
		len--;
	}
}
