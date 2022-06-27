/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:19:14 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/27 17:32:50 by hyunjung         ###   ########.fr       */
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
	{
		occur_error(1);
	}
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

void	indexing_arr(t_stack_data *a)
{
	int	i;
	int	j;
	int	*tmp;
	int	arr_tmp;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * a->size_a);
	if (tmp == 0)
	{
		occur_error(1);
	}
	while (i < a->size_a)
	{
		j = 0;
		tmp[i] = 0;
		arr_tmp = a->a_top->next->content;
		printf("arr_tmp %d\n",arr_tmp);

		while (j < a->size_a)
		{
		printf("a->a_top->content => %d\n", a->a_top->content);
			arr_tmp = a->a_top->next->content;
			if (a->a_top->content > arr_tmp)
			{
				tmp[i]++;
			}
			j++;
		}
		printf("tmp[%d] => %d\n", i, tmp[i]);
		i++;
	}
	free(a->arr);
	a->arr = NULL;
	a->arr = tmp;
}
