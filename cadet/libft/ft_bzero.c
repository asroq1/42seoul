/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:50:19 by hyunjung          #+#    #+#             */
/*   Updated: 2021/11/16 19:15:18 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	bzero(void *s, size_t n)
{
	size_t			idx;
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n != 0)
	{
		str[idx] = 0;
		idx++;
		n--;
	}
}
