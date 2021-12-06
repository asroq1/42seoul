/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:47:51 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/06 14:42:53 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			idx;

	idx = 0;
	tmp1 = (unsigned char *)str1;
	tmp2 = (unsigned char *)str2;
	while (idx < n)
	{
		if (tmp1[idx] > tmp2[idx])
		{
			return (1);
		}
		else if (tmp1[idx] < tmp2[idx])
		{
			return (-1);
		}
		idx++;
	}
	return (0);
}
