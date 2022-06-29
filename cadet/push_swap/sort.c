/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:43:17 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/29 17:39:38 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_stack(t_stack_data *stack)
{
	return (stack->arr[stack->length - 1]);
}

int	bot_stack(t_stack_data *stack)
{
	return (stack->arr[0]);
}

// void	small_case(t_stack_data *a)
// {
// 	// int	top;
// 	// int	mid;
// 	// int	bot;

// 	// top = a->a_top->content;
// 	// mid = a->a_top->next->content;
// 	// bot = a->a_top->next->next->content;
// 	// if (top > mid && mid > bot && top > bot)
// 	// {
// 	// 	sa(a);
// 	// 	rra(a);
// 	// }
// 	// else if (top > mid && bot > mid && top > bot)
// 	// {
// 	// 	ra(a);
// 	// }
// 	// else if (mid > top && mid > bot && bot > top)
// 	// {
// 	// 	sa(a);
// 	// 	ra(a);
// 	// }
// 	// else if (top > mid && bot > mid && bot > top)
// 	// 	sa(a);
// 	// else if (mid > top && mid > bot && top > bot)
// 	// 	rra(a);
// }

// void	a_to_b(t_stack_data *a, t_stack_data *b, int chunk, int i)
// {
// 	int	size;
// 	printf("@@@ a->arr[0] = %d\n", a->arr[0]);
// 	printf("@@@ a->arr[1] = %d\n", a->arr[1]);
// 	printf("@@@ a->arr[2] = %d\n", a->arr[2]);
// 	printf("@@@ a->arr[3] = %d\n", a->arr[3]);
// 	printf("@@@ a->arr[4] = %d\n", a->arr[4]);
// 	printf("@@@ a->arr[5] = %d\n", a->arr[5]);
// 	size = a->size_a - 1;
// 	while (size != 0)
// 	{
// 		printf("size %d \n", size);
// 		printf("hey !!top_stack %d\n", top_stack(a));
// 		if (top_stack(a) <= i)
// 		{
// 			pb(a, b);
// 			i++;
// 		}
// 		else if (top_stack(a) > i && top_stack(a) <= i + chunk)
// 		{
// 			pb(a, b);
// 			rb(b);
// 			i++;
// 		}
// 		else if (top_stack(a) > (i + chunk))
// 		{
// 			if (i < a->size_a / 2 && i >= 0)
// 				rra(a);
// 			else
// 				ra(a);
// 		}
// 		size--;
// 	}
// }

// void	b_to_a(t_stack_data *b, t_stack_data *a)
// {
// 	int	size;

// 	size = b->size_b - 1;
// 	printf("b _ to _ a\n");
// 	while (b->size_a != 0)
// 	{
// 		sort_b(b, size);
// 		pa(a, b);
// 		size--;
// 	}
// }
 
// void	sort_b(t_stack_data *b, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < b->size_b && b->size_b != size)
// 	{
// 		i++;
// 	}
// 	while (i < b->size_b / 2 & i >= 0)
// 	{
// 		rrb(b);
// 		i--;
// 	}
// 	while (i >= b->size_b / 2 && i < b->size_b - 1)
// 	{
// 		rb(b);
// 		i++;
// 	}
// }

// void	small_command(t_stack_data *a, t_stack_data *b)
// {
// 	while (a->length > 3)
// 	{
// 		while (/* condition */)
// 		{
// 			ra(a);
// 		}
// 		pb(a, b);
// 	}
// 	if (a->length == 2 || a->length == 3)
// 	{
// 		sort();
// 	}
// 	while (b->size > 0)
// 	{
// 		pa(a, b);
// 	}
// 	if (/* condition */)
// 	{
// 		sa(a);
// 	}
// }

// void	large_command(t_stack_data *a, t_stack_data *b)
// {
// 	int				chunk;
// 	int				i;
// 	int				x;

// 	i = 0;
// 	x = a->length;
// 	chunk = 0.000000053 * (x * x) + 0.03 * x + 14.5;
// 	a_to_b(a, b, chunk, i);
// 	b_to_a(b, a);
// }

void	sort_stack(t_stack_data *a, t_stack_data *b)
{
	int i = 0;
	printf("=======sorting ..... =============\n");
		printf("a->arr[0] ====> %d\n", a->arr[0]);
		printf("a->arr[1] ====> %d\n", a->arr[1]);
		printf("a->arr[2] ====> %d\n", a->arr[2]);
		printf("a->arr[3] ====> %d\n", a->arr[3]);
	// while (a->arr[i] != 0)
	// {
	// 	printf("a->arr[%d] ====> %d\n", i, a->arr[i]);
	// 	i++;
	// }
	
	// if (a->length <= 5)
	// {
	// 	small_command(a, b);
	// }
	// else
	// {
	// 	large_command(a, b);
	// }
}
