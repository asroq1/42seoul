/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:19:14 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/22 11:55:21 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_arr_size(int argc, char *argv[])
{
	int		i;
	int		j;
	int		size;
	char	**str;

	i = 0;
	size = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (!ft_isspace(argv[i][j]))
				break ;
			j++;
		}
		if (argv[i][j] == '\0')
			occur_error(1);
		str = ft_split(argv[i], ' ');
		size += get_str_size(str);
		free_str(str);
		i++;
	}
	return (size - 1);
}

int	*get_new_arr(int argc, char *argv[], int size)
{
	char	**str;
	int		*new_arr;
	int		argc_count;
	int		arr_count;

	argc_count = 1;
	arr_count = 0;
	new_arr = (int *)malloc(sizeof(int) * size);
	if (new_arr == 0)
		occur_error(1);
	while (argc_count < argc)
	{
		str = ft_split(argv[argc_count], ' ');
		set_str_to_arr(new_arr, str, &arr_count);
		free_str(str);
		argc_count++;
	}
	new_arr[arr_count] = '\0';
	return (new_arr);
}

void	set_str_to_arr(int *arr, char **str, int *arr_count)
{
	int	i;
	int	tmp;

	i = 0;
	while (str[i] != 0)
	{
		tmp = check_numbers(str[i]);
		arr[*arr_count] = tmp;
		(*arr_count)++;
		i++;
	}
}

void	validate_arr(int *arr, int i, int size)
{
	int	j;
	int	tmp;
	int	bomb;

	bomb = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				bomb++;
			}
		j++;
		}
		if (arr[i] == arr[i + 1])
			occur_error(1);
		i++;
	}
	if (bomb == 0)
		occur_error(1);
}
