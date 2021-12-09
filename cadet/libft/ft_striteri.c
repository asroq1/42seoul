/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:01:16 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/09 13:27:00 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_strlen(s);
	if (s == 0 || f == 0)
	{
		return (0);
	}
	while (i < length)
	{
		f(i, &s[i]);
		i++;
	}
}
