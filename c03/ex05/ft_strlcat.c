/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:50:05 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/21 12:09:15 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		str++;
		cnt++;
	}
	return (cnt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_length;
	unsigned int	dest_length;
	unsigned int	i;
	unsigned int	j;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (dest_length <= src_length)
	{
		return (src_length + size);
	}
	i = dest_length;
	j = 0;
	while (src[j] && (i + j + 1 < size))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest_length + src_length);
}
