/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:54:13 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/15 11:46:30 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_bonus(t_stack_data *a, t_stack_data *b, char *command)
{
	if (compare_command(command, "sa") == 0)
		bonus_sa(a);
	else if (compare_command(command, "sb") == 0)
		bonus_sb(b);
	else if (compare_command(command, "ss") == 0)
		bonus_ss(a, b);
	else if (compare_command(command, "pa") == 0)
		bonus_pa(a, b);
	else if (compare_command(command, "pb") == 0)
		bonus_pb(a, b);
	else if (compare_command(command, "ra") == 0)
		bonus_ra(a);
	else if (compare_command(command, "rb") == 0)
		bonus_rb(b);
	else if (compare_command(command, "rr") == 0)
		bonus_rr(a, b);
	else if (compare_command(command, "rra") == 0)
		bonus_rra(a);
	else if (compare_command(command, "rrb") == 0)
		bonus_rrb(b);
	else if (compare_command(command, "rrr") == 0)
		bonus_rrr(a, b);
	else
		occur_error(1);
}

void	check_command(t_stack_data *a, t_stack_data *b)
{
	char	*command;

	command = get_command(0);
	while (command)
	{
		command_bonus(a, b, command);
		free(command);
		command = 0;
		command = get_command(0);
	}
	free(command);
	command = 0;
}

char	*get_command(int fd)
{
	char	*command;
	char	*result;

	command = get_next_line(fd);
	result = ft_strtrim(command, "\n");
	free(command);
	command = 0;
	return (result);
}

void	print_result(t_stack_data *a, t_stack_data *b)
{
	if (b->length == 0 && check_input(a))
	{
		free(a->arr);
		free(b->arr);
		ft_putstr_fd("OK\n", 1);
		exit(SUCCESS);
	}
	else
	{
		free(a->arr);
		free(b->arr);
		ft_putstr_fd("KO\n", 1);
		exit(FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_stack_data	a;
	t_stack_data	b;

	if (argc < 2)
	{
		exit (1);
	}
	get_stack(&a);
	input_validater(&a, argv);
	get_b(&b, a.total);
	check_command(&a, &b);
	print_result(&a, &b);
	return (0);
}
