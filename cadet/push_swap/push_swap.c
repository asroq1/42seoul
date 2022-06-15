/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:33 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/15 16:11:26 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*make_new_stack(void)
{
	t_node	*new_mem;

	new_mem = NULL;
	new_mem = malloc(sizeof(t_node));
	new_mem->content = 0;
	new_mem->next = NULL;
	return (new_mem);
}

t_stack_data	*get_new_stacks(void)
{
	t_stack_data	*new_mem;
	t_node			*stack_a;

	new_mem = NULL;
	new_mem = malloc(sizeof(t_stack_data));
	stack_a = make_new_stack();
	new_mem->arr = NULL;
	new_mem->size_a = 0;
	new_mem->a_top = stack_a;
	new_mem->a_bottom = stack_a;
	new_mem->size_b = 0;
	return (new_mem);
}

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
		{
			occur_error();
		}
		str = ft_split(argv[i], ' ');
		size += get_str_size(str);
		free_str(str);
		i++;
	}
	return (size - 1);
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

int	main(int argc, char *argv[])
{
	int				arr_size;
	int				*num_arr;
	t_stack_data	*stack_data;

	arr_size = 0;
	if (argc < 2)
	{
		occur_error();
	}
	// stack_data = get_new_stacks();
	arr_size = get_arr_size(argc, argv);
	// input_validater(argv);
}
