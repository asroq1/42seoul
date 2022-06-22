/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:33 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/22 13:26:36 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int				arr_size;
	int				*num_arr;
	t_stack_data	*stack_data;

	arr_size = 0;
	if (argc < 2)
	{
		occur_error(1);
	}
	printf("// 1. 새로운 스택을 만들어준다.\n");
	stack_data = get_new_stacks();
	printf("// 2. 입력값으로 들어온 배열의 크기를 구해준다\n");
	arr_size = get_arr_size(argc, argv);
	printf("// 3. 사이즈를 바탕으로 배열을 동적할당 해준다.\n");
	num_arr = get_new_arr(argc, argv, arr_size);
	printf("// 4. 받아온 배열을 스택에 담아준다.\n");
	change_to_stack(stack_data, num_arr, arr_size);
	printf("// 5.배열을 재정렬해준다.\n");
	validate_arr(num_arr, 0, arr_size);
	printf("6. 스택 내의 배열을 정렬된 배열로 바꿔줌\n");
	stack_data->arr = num_arr;
	printf("stack_Data->arr =====> %d\n", stack_data->arr[0]);
	printf("stack_Data->arr =====> %d\n", stack_data->arr[1]);
	printf("stack_Data->arr =====> %d\n", stack_data->arr[2]);
	printf("// 6. 정렬된 배열을 스택에 채워준다.\n");
	int i = 0;
	while (stack_data->arr[i] != 0)
	{
		printf("stack_data->arr is %d\n", stack_data->arr[i]);
		i++;
	}
	printf("// 7. 스택을 정렬해준다. \n");
	sort_stack(stack_data);
	i = 0;
	printf("-----------after soring ---------\n");
	while (stack_data->arr[i] != 0)
	{
		printf("stack_data->arr is %d\n", stack_data->arr[i]);
		i++;
	}
	return (0);
}
