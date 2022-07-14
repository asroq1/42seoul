/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:03:48 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/14 16:56:47 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_H
# define PHILO_H

# define  SUCCESS 	1
# define  FAILURE 	1
# define  BASIC		5
# define  OPTIONAL 	6

/* usleep */
# include <unistd.h>

/* pthread func */
# include <pthread.h>

/* gettimeofday - get date and time */
# include <sys/time.h>

//테스트용 stdio.h
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
	int			cnt_of_must_eat;
	int			finish;
	int			finish_to_eat;
	long long	start;
}				t_input;

int		print_error(char *str, int code);
int		ft_atoi(const char *str);
int		init_input(t_input *input, int argc, char *argv);

#endif