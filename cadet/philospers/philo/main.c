/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:52:41 by hyunjung          #+#    #+#             */
/*   Updated: 2022/08/19 14:19:41 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;
	int		error;

	error = 0;
	error = init_info(&info, argc, argv, error);
	if (error != 0)
		return (print_error("init_info Error", error));
	error = init_mutex(&info);
	if (error != 0)
		return (print_error("mutext init Error", error));
	error = init_philo(&info, &philo);
	if (error != 0)
		return (print_error("init_philo Error", error));
	error = execute_thread(&info, philo);
	if (error)
		return (print_error("Error philo start", error));
	while (1)
	{
	}
	return (0);
}
