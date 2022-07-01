/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:07:41 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/01 16:30:44 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_command(const char *str1, const char *str2)
{
	int		i;

	i = 0;
	while (*(str1 + i) && *(str1 + i) == *(str2 + i))
		i++;
	return (*((unsigned char *)str1 + i) - *((unsigned char *)str2 + i));
}

void	occur_error(int err)
{	
	if (err == 1)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	if (err == 2)
	{
		ft_putstr_fd("command error\n", 1);
		exit(1);
	}
}

int	get_str_size(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}
