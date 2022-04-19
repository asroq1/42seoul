/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:26:06 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/19 11:56:52 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	utils_strlcpy(char *dest, char *src, int length)
{
	int	i;
	int	src_length;

	i = 0;
	src_length = 0;
	while (src[i++] != 0)
	{
		src_length++;
	}
	if (length == 0)
	{
		return (src_length);
	}
	i = 0;
	while (i < length - 1 && *src != 0 && *src != '\n')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = 0;
	return (src_length);
}

char	*utils_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	else if (s1 == 0)
		return (utils_strdup(s2));
	else if (s2 == 0)
		return (utils_strdup(s1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new_str = malloc(i + j);
	if (new_str == 0)
	{
		return (0);
	}
	utils_strlcpy(new_str, s1, i + 1);
	utils_strlcpy(new_str + i, s2, j + 1);
	free(s1);
	free(s2);
	return (new_str);
}

char	*utils_strdup(char *str)
{
	int		i;	
	int		length;
	char	*new_str;

	i = 0;
	new_str = 0;
	length = ft_strlen(str);
	new_str = malloc(length + 1);
	if (new_str == 0)
	{
		return (0);
	}
	while (str[i] != 0 && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
