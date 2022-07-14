/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:52:41 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/14 16:56:55 by hyunjung         ###   ########.fr       */
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
		/* argc는 5개 아니면 무조건 6개이다.*/
		return (print_error("error input", 3));
	}
	/* memset함수를 사용해서 input에다가 input구조체 사이즈만큼으로 0을 채워서 동적할당*/
	memset(&input, 0, sizeof(t_input));
	/* argv를 input구조체에 저장하고, 필요한 변수를 할당 및 초기화 */
	error = init_input(&input, argc, argv);
	if (error != 0)
	{
		return (print_error("error input init", error));
	}
	/* 철학자마다 들어갈 변수 초기화 */
	error = init_philo(&philo, &input);
	if (error)
	{
		return (print_error("error philo init", error));
	}
	/* 본게임을 시작하고 종료할 때까지 동작.*/
	error = philo_start(&input, philo);
	if (error)
	{
		return (print_error("error philo start", error));
	}
	return (0);
}
