/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:16:23 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/09 19:14:55 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{	
	size_t			i;
	char			*tmp;

	i = 0;
	tmp = malloc(ft_strlen(s1) * sizeof(char));
	while (s1[i] != 0)
	{
		tmp[i] = s1[i];
		i++;
	}
	return (tmp);
}
