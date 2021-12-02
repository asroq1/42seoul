/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:10:21 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/02 16:40:30 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size > i + 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		printf("i == %d\n", i);
	}
	dest[i] = '\0';
	while (src[i] != '\0')
	{
		++i;
		printf("after : %d \n", i);
	}
	return (i);
}
