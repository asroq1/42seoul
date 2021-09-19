/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:56:48 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/19 16:01:45 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlength(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;
	int src_length;
	int dest_length;
	
	i = 0;
	src_length = ft_strlength(src);
	dest_length = ft_strlength(dest);

	while (/* condition */)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	
}