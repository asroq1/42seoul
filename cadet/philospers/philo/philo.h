/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:03:48 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/08 18:33:02 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
//ㅌㅔ스트용 stdio.h
# include <stdio.h>

typedef struct s_philo
{
	struct s_input	*arg;
	int				id;
	int				right;
	int				left;
	long long		last_food_time;
	int				eat_counter;
}				t_philo;

typedef struct s_input
{
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			eat_times;
	int			finish;
	int			finish_to_eat;
	long long	start;
}				t_input;

int	occur_error(char *str, int no);

#endif