/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 23:30:31 by hyunjung          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/09/26 18:55:08 by hyunjung         ###   ########.fr       */
=======
/*   Updated: 2021/09/25 10:10:19 by hyunjung         ###   ########.fr       */
>>>>>>> 0fcd5bfb7b0a0f0d32a21325955e0092e1c9b8bd
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*new_src;

	i = 0;
	new_src = malloc(sizeof(char) * ft_strlen(src) + 1);
<<<<<<< HEAD
	if (new_src == 0)
	{
		return (0);
	}
=======
>>>>>>> 0fcd5bfb7b0a0f0d32a21325955e0092e1c9b8bd
	while (src[i] != '\0')
	{
		new_src += src[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}
