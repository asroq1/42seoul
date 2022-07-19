/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:52:41 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/19 11:24:48 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char *argv[])
{
	t_input	input;
	t_philo	*philo;
	int		error;

	if (argc != 5 && argc != 6)
		return (print_error("error input", 3));
	memset(&input, 0, sizeof(t_input));
	error = init_input(&input, argc, argv);
	if (error)
		return (print_error("error input init", error));
	error = init_mutex(&input, argc, argv);
	if (error)
		return (print_error("error mutext init", error));
	error = init_philo(&philo, &input);
	if (error)
		return (print_error("error philo init", error));
	error = philo_start(&input, philo);
	if (error)
		return (print_error("error philo start", error));
	return (0);
}
