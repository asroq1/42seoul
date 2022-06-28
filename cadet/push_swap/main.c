/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:33 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/28 15:24:16 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int				arr_size;
	int				*arr;
	t_stack_data	*a;
	t_stack_data	*b;

	arr_size = 0;
	if (argc < 2)
	{
		occur_error(1);
	}
	printf("// 1. 새로운 스택을 만들어준다.\n");
	a = get_new_stacks();
	printf("// 2. 입력값으로 들어온 배열의 크기를 구해준다\n");
	arr_size = get_arr_size(argc, argv);
	printf("// 3. 사이즈를 바탕으로 배열을 동적할당 해준다.\n");
	arr = get_new_arr(argc, argv, arr_size);
	printf("// 4. 받아온 배열을 스택에 담아준다.\n");
	change_to_stack(a, arr, arr_size);
	indexing_arr(a, arr, arr_size);
	printf("// 5.배열을 재정렬해준다.\n");
	printf("6. 스택 내의 배열을 정렬된 배열로 바꿔줌\n");
	// a->arr = arr;
	make_b_stack(b);
	printf("// 7. 스택을 정렬해준다. \n");
	sort_stack(a, b);
	return (0);
}
