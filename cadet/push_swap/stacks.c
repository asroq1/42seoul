/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:08:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/17 21:29:21 by hyunjung         ###   ########.fr       */
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
