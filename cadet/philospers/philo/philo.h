/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:03:48 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/19 17:38:52 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_H
# define PHILO_H

# define  BASIC		5
# define  OPTIONAL 	6

/* usleep */
# include <unistd.h>

/* pthread func */
# include <pthread.h>

/* gettimeofday - get date and time */
# include <sys/time.h>

/* memeset */
# include <string.h>

/* exit */
# include <stdlib.h>

//테스트용 stdio.h
# include <stdio.h>

typedef struct s_philo
{
	int				id;
	int				right;
	int				left;
	long long		last_food_time;
	int				cnt_of_eat;
	pthread_t		thread;
	struct s_info	*info;
}				t_philo;

typedef struct s_info
{
	int				cnt_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				cnt_of_must_eat;
	int				finish;
	int				finish_to_eat;
	long long		time_to_start;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
}				t_info;

/* utils.c */
int		print_error(char *str, int code);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		get_time(void);

/* init.c */
int		init_info(t_info *input, int argc, char *argv[]);
int		init_mutex(t_info *info);
int		init_philo(t_philo **philo, t_info *info);

#endif