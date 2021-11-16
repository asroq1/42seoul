/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:50:05 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/22 20:16:43 by hyunjung         ###   ########.fr       */
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

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	i = 0;
	if (size < dest_length)
	{
		return (src_length + size);
	}
	else
	{
		while (src[i] != '\0' && dest_length + 1 + i < size)
		{
			dest[dest_length + i] = src[i];
			i++;
		}
		dest[dest_length + i] = '\0';
		return (dest_length + src_length);
	}
}
