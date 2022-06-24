/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:43:17 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/24 15:12:05 by hyunjung         ###   ########.fr       */
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

void	large_case(t_stack_data *stack)
{
	int	a;
	int	b;

	// 피봇을 기준으로 b스택에 내림차순으로 수들을 정렬해준다.
	// 1 4 2 5의 경우 아래와 같이 값이 담겨있다.
	// a = [4 , 5]
	// b = [2 , 1]
	get_pivot_info(stack);
	while (stack->size_a > 3)
		pb(stack);
	if (stack->size_a == 2)
	{
		if (stack->a_top->content > stack->a_top->next->content)
			sa(stack);
	}
	if (stack->size_a == 3)
		small_case(stack);
	// //위의 예외를 통해서 다시 한 번 정렬을 해준다.
	// 현재 a스택의 경우에는 정렬이 잘된 상태라서 그대로이다.
	// a = [4 , 5]
	// b = [2 , 1]
	while (stack->size_b != 0)
	{
		a = 0;
		b = 0;
		get_min_rotate(stack, &a, &b);
		get_rotate_same(stack, &a, &b);
		get_rotate_a(stack, a);
		get_rotage_b(stack, b);
		pa(stack);
	}
	last_sorting(stack);
	// 루프를 돌리고 나면 a스택에 [1 ,2, 4, 5] 순으로 정렬이 돼있다.
}

void	ft_get_bigger(int a, int b, int a_pos, int b_pos)
{
	if (a < 0)
	{
		a = a * -1;
	}
	if (b < 0)
	{
		b = b * -1;
	}
	if (a_pos < 0)
	{
		a_pos = a_pos * -1;
	}
	if (b_pos < 0)
	{
		b_pos = b_pos * -1;
	}
	if (a + b > a_pos + b_pos)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	get_min_rotate(t_stack_data *stack, int *a, int *b)
{
	int		a_position;
	int		b_position;
	int		i;
	int		n;
	t_node	*stack_b;

	i = 0;
	stack_b = stack->b_top;
	while (i < stack->size_b)
	{
		n = stack_b->content;
		a_position = set_a_position(n, stack);
		if (i >= (stack->size_b + 1) / 2)
			b_position = (stack->size_a - i) * -1;
		else
			b_position = i;
		if (i == 0 || ft_get_bigger(*a, *b, a_position, b_position))
		{
			*a = a_position;
			*b = b_position;
		}
	stack_b = stack_b->next;
	i++;
	}
}

void	sort_stack(t_stack_data *stack_data)
{
	if (stack_data->size_a == 2)
	{
		if (stack_data->a_top->content > stack_data->a_top->next->content)
		{
			sa(stack_data);
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
}
