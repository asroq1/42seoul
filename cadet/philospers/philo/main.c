/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:52:41 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/19 17:02:51 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;
	int		error;

	if (argc != 5 && argc != 6)
		return (print_error("Error input", 3));
	error = init_info(&info, argc, argv);
	if (error != 0)
		return (print_error("Error input init", error));
	error = init_mutex(&info);
	if (error != 0)
		return (print_error("Error mutex init", error));
	error = init_philo(&philo, &info);
	if (error != 0)
		return (print_error("Error philo init", error));
	// error = philo_start(&info, philo);
	// if (error)
	// 	return (print_error("Error philo start", error));
	return (0);
}
