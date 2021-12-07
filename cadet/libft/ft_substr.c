/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:38:14 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/07 17:56:38 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*new_str;
	size_t			i;
	size_t			j;

	i = start;
	j = 0;
	if (s == 0)
	{
		return (0);
	}
	new_str = malloc(len * sizeof(char));
	while (j < len && s != 0)
	{
		new_str[j] = s[i];
		i++;
		j++;
	}
	new_str[j] = 0;
	return (new_str);
}
