/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:43:17 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/28 16:13:26 by hyunjung         ###   ########.fr       */
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

void	a_to_b(t_stack_data *a, t_stack_data *b, int chunk, int i)
{
	int	size;

	printf("@@@ a->arr[] = %d\n", a->arr[0]);
	printf("@@@ a->arr[] = %d\n", a->arr[1]);
	printf("@@@ a->arr[] = %d\n", a->arr[2]);
	printf("@@@ a->arr[] = %d\n", a->arr[3]);
	printf("@@@ a->arr[] = %d\n", a->arr[4]);
	printf("@@@ a->arr[] = %d\n", a->arr[5]);
	size = a->size_a - 1;
	printf("a _ to _ b \n");
	while (size != 0)
	{
		printf("top ! ! stack->arr[stack->size - 1] -> %d\n", a->arr[size - 1]);
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
	int	size;

	size = b->size_b - 1;
	printf("b _ to _ a\n");
	while (b->size_a != 0)
	{
		sort_b(b, size);
		pa(b);
		size--;
	}
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

void	large_case(t_stack_data *a, t_stack_data *b)
{
	int				chunk;
	int				i;
	int				x;

	i = 0;
	x = a->size_a;
	chunk = 0.000000053 * (x * x) + 0.03 * x + 14.5;
	printf("before timer....\n");
	printf("stack a => %d\n", a->a_top->content);
	printf("stack a => %d\n", a->a_top->next->content);
	printf("stack a => %d\n", a->a_top->next->next->content);
	printf("stack a => %d\n", a->a_top->next->next->next->content);
	printf("=----------------------------------=-\n");
	printf("a arr[0] => %d\n", a->arr[0]);
	printf("a arr[1] => %d\n", a->arr[1]);
	printf("a arr[2] => %d\n", a->arr[2]);
	printf("a arr[3] => %d\n", a->arr[3]);
	a_to_b(a, b, chunk, i);
	b_to_a(b, a);
}

void	sort_stack(t_stack_data *a, t_stack_data *b)
{
	if (a->size_a == 2)
	{
		if (a->a_top->content > a->a_top->next->content)
		{
			sa(a);
		}
	}
	else if (a->size_a == 3)
	{
		small_case(a);
	}
	else
	{
			//2 ~ 3개보다 더 큰 인자들은 피봇을 통해 다시 재분류.
			large_case(a, b);
	}
}
