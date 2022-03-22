/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:16:23 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/10 14:26:19 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{	
	size_t			i;
	size_t			lenght;
	char			*tmp;

	i = 0;
	lenght = ft_strlen(s1);
	tmp = malloc(lenght * sizeof(char) + 1);
	if (tmp == 0)
	{
		return (0);
	}
	while (i < lenght)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
