/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:33 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/11 17:55:36 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_data	a;
	t_stack_data	b;

	if (argc < 2)
	{
		exit(1);
	}
	get_stack(&a);
	input_validater(&a, argv);
	indexing_arr(&a);
	get_b(&b, a.total);
	sort_stack(&a, &b);
	free(a.arr);
	free(b.arr);
	return (0);
}
