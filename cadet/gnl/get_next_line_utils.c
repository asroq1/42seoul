/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:21:28 by hyunjung          #+#    #+#             */
/*   Updated: 2022/01/06 16:54:42 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == c)
	{
		return ((char *)&str[i]);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != 0)
	{
		i++;
		cnt++;
	}
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (new_str == 0)
		return (0);
	while (i < ft_strlen(s1))
	{
		new_str[i] = s1[i];
		j = 0;
		i++;
	}
	while (j <= ft_strlen(s2))
	{
		new_str[i] = s2[j];
		j++;
		i++;
	}
	return (new_str);
}
