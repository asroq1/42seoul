/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:33 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/28 18:53:51 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_data	a;
	t_stack_data	b;

	if (argc < 2)
	{
		occur_error(1);
	}
	printf("// 1. 새로운 스택을 만들어준다.\n");
	get_stack(&a);
	printf("// 2. 입력값 유효성 검사 및 a스택 만들기\n");
	input_validater(&a, argv);
// 	arr_size = get_arr_size(argc, argv);
// 	printf("// 3. 사이즈를 바탕으로 배열을 동적할당 해준다.\n");
// 	arr = get_new_arr(argc, argv, arr_size);
// // 4. 받아온 배열을 스택에 담아준다.\n");	printf("
// 	change_to_stack(a, arr, arr_size);
// 	indexing_arr(a, arr, arr_size);
// 	// a->arr = arr;
// 	make_b_stack(b);
// 	sort_stack(a, b);
}
