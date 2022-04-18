/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:21:28 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/18 17:38:06 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str == 0)
	{
		return (0);
	}
	while (str[i] != 0)
	{
		if (str[i] == c)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1_length;
	int		s2_length;

	if (s1 == 0)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == 0)
		return (ft_strdup(s2));
	else if (s2 == 0)
		return (ft_strdup(s1));
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	str = malloc(s1_length + s2_length);
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, s1_length + 1);
	ft_strlcpy(str + s1_length, s2, s2_length + 1);
	return (str);
}

char	*ft_strdup(const char *s1)
{	
	size_t			i;
	size_t			length;
	char			*tmp;

	i = 0;
	length = ft_strlen(s1);
	tmp = malloc(length * sizeof(char) + 1);
	if (tmp == 0)
	{
		return (0);
	}
	while (s1[i] != 0 && s1[i] != '\n')
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;
	int	length;

	length = 0;
	i = 0;
	while (src[length] != 0)
	length++;
	if (size == 0)
		return (length);
	while (i < size - 1 && *src != 0 && *src != '\n')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (length);
}
