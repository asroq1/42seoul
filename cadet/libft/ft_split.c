/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:29:05 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/13 19:45:26 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_numbers(const char *str, char c)
{
	size_t	i;
	size_t	numbers;
	size_t	length;

	i = 0;
	numbers = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		if (str[i] == c)
		{
			numbers++;
		}
		i++;
	}
	numbers += 1;
	return (numbers);
}

static	void	*get_free(char **mem, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		free(mem[i]);
		i++;
	}
	free(mem);
	return (0);
}

void	ft_strcpy(char *dest, char const *src, int start, int last)
{
	size_t	i;

	i = 0;
	while (start < last)
	{
		dest[i] = src[i];
		i++;
		start++;
	}
	dest[i] = 0;
}

static void	get_result(char const *str, char **new_str, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] != 0 && str[i] != c)
		{
			start = i;
			while (str[i] != 0 && str[i] != c)
				i++;
			(new_str[j] = malloc(sizeof(char) * (i - start + 1)));
			if (new_str[j] == 0)
			{
				get_free(new_str, j);
				return ;
			}
			ft_strcpy(new_str[j], str, start, i);
			j++;
		}
		else if (str[i] != 0)
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	size_t	n;

	if (s == 0)
	{
		return (0);
	}
	n = get_numbers(s, c);
	new_str = malloc(sizeof(char *) * (n + 1));
	if (new_str == 0)
	{
		return (0);
	}
	new_str[n] = 0;
	if (n == 0)
	{
		return (new_str);
	}
	get_result(s, new_str, c);
	return (new_str);
}
