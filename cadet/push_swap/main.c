/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:33 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/29 17:39:33 by hyunjung         ###   ########.fr       */
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
	printf("// 3. 값들을 인덱싱 해줌\n");
	indexing_arr(&a);
	printf("// 4. b스택을 생성해준다.\n");
	get_b(&b, a.total);
	sort_stack(&a, &b);
}
