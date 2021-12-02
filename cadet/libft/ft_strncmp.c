/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:33:23 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/02 19:48:58 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	strncmp(const char	*str1, const char	*str2, size_t n)
{	
	size_t	idx;

	idx = 0;
	while (n != 0)
	{
		if (str1[idx] != str2[idx] && str1[idx] > str2[idx])
		{
			return (1);
		}
		else if (str1[idx] != str2[idx] && str1[idx] < str2[idx])
		{
			return (-1);
		}
		idx++;
		n--;
	}
	return (0);
}
