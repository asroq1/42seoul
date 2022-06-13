/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:33 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/13 15:48:24 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*node;
	int		arr_size;
	int		*num_arr;

	arr_size = 0;
	if (argc < 2)
	{
		occur_error();
	}
	input_validater(argv);
}
