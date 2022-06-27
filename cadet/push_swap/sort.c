/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:43:17 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/27 13:38:32 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_case(t_stack_data *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->a_top->content;
	mid = a->a_top->next->content;
	bot = a->a_top->next->next->content;
	if (top > mid && mid > bot && top > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && bot > mid && top > bot)
	{
		ra(a);
	}
	else if (mid > top && mid > bot && bot > top)
	{
		sa(a);
		ra(a);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(a);
	else if (mid > top && mid > bot && top > bot)
		rra(a);
}

void	sort_b(t_stack_data *b, int size)
{
	int	i;

	i = 0;
	while (i < b->size_b && b->size_b != size)
	{
		i++;
	}
	while (i < b->size_b / 2 & i >= 0)
	{
		rrb(b);
		i--;
	}
	while (i >= b->size_b / 2 && i < b->size_b - 1)
	{
		rb(b);
		i++;
	}
}

void	a_to_b(t_stack_data *a, t_stack_data *b, int chunk, int i)
{
	printf("!!!!!!!!!! a _ to _ b\n");

	int	size;

	size = a->size_a - 1;
	while (size != 0)
	{
		if (a->a_top->content <= i)
		{
			pb(a);
			i++;
		}
		else if (a->a_top->content > i && a->a_top->content < i + chunk)
		{
			pb(a);
			rb(b);
			i++;
		}
		else if (a->a_top->content > (i + chunk))
		{
			if (i < a->size_a / 2 && i >= 0)
				rra(a);
			else
				ra(a);
		}
		size--;
	}
}

void	b_to_a(t_stack_data *b, t_stack_data *a)
{
	printf("!!!!!!!!!! b _ to _ a\n");
	int	size;

	size = b->size_b - 1;
	while (b->size_a != 0)
	{
		sort_b(b, size);
		pa(b);
		size--;
	}
}

void	large_case(t_stack_data *stack)
{
	int				chunk;
	int				i;
	int				x;
	t_stack_data	*a;
	t_stack_data	*b;

	i = 0;
	x = stack->size_a;
	chunk = 0.000000053 * (x * x) + 0.03 * x + 14.5;
	printf("before timer....\n");
	printf("stack a => %d\n", stack->a_top->content);
	printf("stack a => %d\n", stack->a_top->next->content);
	printf("stack a => %d\n", stack->a_top->next->next->content);
	printf("stack a => %d\n", stack->a_top->next->next->next->content);

	printf("stack bbb => %d\n", stack->b_top->content);
	printf("stack bbb => %d\n", stack->b_top->next->content);
	printf("stack bbb => %d\n", stack->b_top->next->next->content);
	printf("stack bbb => %d\n", stack->b_top->next->next->next->content);

	a_to_b(a, b, chunk, i);
	b_to_a(b, a);
}

// void	get_min_rotate(t_stack_data *stack, int *a, int *b)
// {
// 	int		a_position;
// 	int		b_position;
// 	int		i;
// 	int		n;
// 	t_node	*stack_b;

// 	i = 0;
// 	stack_b = stack->b_top;
// 	while (i < stack->size_b)
// 	{
// 		n = stack_b->content;
// 		a_position = set_a_position(n, stack);
// 		if (i >= (stack->size_b + 1) / 2)
// 			b_position = (stack->size_a - i) * -1;
// 		else
// 			b_position = i;
// 		if (i == 0 || ft_get_bigger(*a, *b, a_position, b_position))
// 		{
// 			*a = a_position;
// 			*b = b_position;
// 		}
// 	stack_b = stack_b->next;
// 	i++;
// 	}
// }

void	sort_stack(t_stack_data *stack_data)
{
	printf("sorting ...........\n");
	if (stack_data->size_a == 2)
	{
		if (stack_data->a_top->content > stack_data->a_top->next->content)
		{
			sa(stack_data);
		}
	}
	else if (stack_data->size_a == 3)
	{
		small_case(stack_data);
	}
	else
	{
			//2 ~ 3개보다 더 큰 인자들은 피봇을 통해 다시 재분류.
			large_case(stack_data);
	}
}
