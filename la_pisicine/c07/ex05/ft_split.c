/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:25:56 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/28 18:32:18 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

long long	ft_strlen(char *str, char *charset)
{
	long long		cnt;

	cnt = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			str++;
			cnt++;
			while (*str && !is_charset(*str, charset))
				str++;
			str--;
		}
		str++;
	}
	return (cnt);
}

void	ft_strcpy(char *dest, char *src, char *last)
{
	while (src < last)
		*(dest)++ = *(src)++;
	*dest = 0;
}

char	**ft_split(char *str, char *charset)
{
	char		**ans;
	char		*tmp;
	int			i;

	i = 0;
	ans = (char **)malloc(sizeof(char *) * ft_strlen(str, charset) + 1);
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			tmp = str;
			str++;
			while (!is_charset(*str, charset) && *str)
				++str;
			ans[i] = (char *)malloc(str - tmp + 1);
			ft_strcpy(ans[i++], tmp, str);
		}
		str++;
	}
	ans[i] = 0;
	return (ans);
}
