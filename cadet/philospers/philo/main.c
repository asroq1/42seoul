/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:52:41 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/08 18:27:50 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char *argv[])
{
	t_input	input;
	t_philo	*philo;
	int		error;

	if (argc != 5 && argc != 6)
	{
		return (occur_error("error input", 3));
	}
	memset(&input, 0, sizeof(t_input));
	error = ft_arg_init(&input, argc, argv);
	if (error)
	{
		return (occur_error("error input init", error));
	}
	error = ft_philo_init(&philo, &input);
	if (error)
	{
		return (occur_error("error philo init", error));
	}
	error = ft_philo_start(&input, philo);
	if (error)
	{
		return (occur_error("error philo start", error));
	}
	return (0);	
}
