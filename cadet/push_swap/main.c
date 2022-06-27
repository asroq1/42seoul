/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:33 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/27 15:22:50 by hyunjung         ###   ########.fr       */
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
	printf("============Before indexing==============\n");
	printf("size %d\n", stack_data->size_a);
	printf("stack a => %d\n", stack_data->a_top->content);
	printf("stack a => %d\n", stack_data->a_top->next->content);
	printf("stack a => %d\n", stack_data->a_top->next->next->content);
	printf("stack a => %d\n", stack_data->a_top->next->next->next->content);
	indexing_arr(stack_data);
	printf("!!!!!!!!!!!\n");
	printf("6. 스택 내의 배열을 정렬된 배열로 바꿔줌\n");
	stack_data->arr = num_arr;
	int i = 0;
	make_b_stack(stack_data);
	// printf("stack bbb => %d\n", stack_data->b_top->content);

	printf("============BBBBBBB==============\n");
	// printf("stack bbb => %d\n", stack_data->b_top->content);
	// printf("stack bbb => %d\n", stack_data->b_top->next->content);
	// printf("stack bbb => %d\n", stack_data->b_top->next->next->content);
	// printf("stack bbb => %d\n", stack_data->b_top->next->next->next->content);

	printf("// 7. 스택을 정렬해준다. \n");
	sort_stack(stack_data);
	return (0);
}