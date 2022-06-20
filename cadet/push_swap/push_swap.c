/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:33 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/20 17:59:21 by hyunjung         ###   ########.fr       */
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
			occur_error();
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
		occur_error();
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
	stack_data = get_new_stacks();
	printf("// 1. 새로운 스택을 만들어준다.\n");
	// 2. 입력값으로 들어온 인자의 배열 사이즈를 구해준다.
	arr_size = get_arr_size(argc, argv);
	printf("// 2. 입력값으로 들어온 \n");
	// 3. 사이즈를 바탕으로 배열을 동적할당 해준다.
	num_arr = get_new_arr(argc, argv, arr_size);
	printf("// 3. 사이즈를 바탕으로 배열을 동적할당 해준다.\n");
	// input_validater(argv);
	// 4. 받아온 배열을 스택으로 변환한다.
	change_to_stack(stack_data, num_arr, arr_size);
	printf("// 4. 받아온 배열을 스택으로 변환한다.\n");
	// 5.배열의 정령을 확인한다.
	validate_arr(num_arr, 0, arr_size);
	printf("// 5.배열의 정령을 확인한다.\n");
	// 6. 스택 내의 배열을 채워줌
	stack_data->arr = num_arr;
	printf("// 6. 스택 내의 배열을 채워줌\n");
	int i = 0;
	while (stack_data->arr[i] != 0)
	{
		printf("stack is %d\n", stack_data->arr[i]);
		i++;
	}
	
	// 7. 스택을 정렬해준다.
	// sort_stack(stack_data);
	// printf("// 7. 스택을 정렬해준다. \n");
	return (0);
}
