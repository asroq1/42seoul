/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:16:37 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/28 12:37:25 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *str, const char *substr, int n)
{
	int			i;
	int			j;

	i = 0;
	if (*substr == 0)
	{
		return ((char *)str);
	}
	while (str[i] != 0 && i < n)
	{
		j = 0;
		while (str[i + j] == substr[j] && i + j < n)
		{
			j++;
			if (substr[j] == 0)
			{
				return ((char *)&str[i]);
			}
		}	
		i++;
	}
	return (0);
}

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	return (0);
}

static char	**do_split(char **new_str, char const *s, char c, int count)
{
	int	i;
	int	j;
	int	next;

	i = 0;
	j = 0;
	while (s[i] != 0 && j < count)
	{
		if (s[i] != c)
		{
			next = i + 1;
			while (s[next] != 0 && s[next] != c)
				next++;
			new_str[j] = ft_substr(s, i, next - i);
			if (new_str[j] == 0)
				return (ft_free(new_str));
			j++;
			i = next;
		}
		else
			i++;
	}
	new_str[j] = 0;
	return (new_str);
}

char	*ft_substr(char const *s, int start, int len)
{
	char			*new_str;
	int				i;
	int				j;

	i = start;
	j = 0;
	if (s == 0)
		return (0);
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		new_str[0] = 0;
		return (new_str);
	}
	while (j < len && s != 0)
	{
		new_str[j] = s[i];
		i++;
		j++;
	}
	new_str[j] = 0;
	return (new_str);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	int		word_count;
	int		i;

	if (s == 0)
		return (0);
	i = 0;
	word_count = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			word_count++;
			while ((s[i] != c) && s[i] != 0)
				i++;
		}
		else
			i++;
	}
	new_str = malloc(sizeof(char *) * (word_count + 1));
	if (new_str == 0)
		return (0);
	do_split(new_str, s, c, word_count);
	return (new_str);
}
