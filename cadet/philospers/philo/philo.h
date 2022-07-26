/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:03:48 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/26 17:27:15 by hyunjung         ###   ########.fr       */
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

/* printf */
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
	long long		time_to_start;
	int				finish_to_eat;
	int				cnt_of_must_eat;
	int				death;
	pthread_mutex_t	check_eat_cnt;
	pthread_mutex_t	check_last_food;
	pthread_mutex_t	check_death;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
}				t_info;

/* utils.c */
int		print_error(char *str, int code);
int		ft_atoi(const char *str);
void	check_death(t_info *info, t_philo *philo);
int		get_time(void);
int		ft_isdigit(int arg);

/* init.c */
int		init_info(t_info *info, int argc, char *argv[], int err);
int		init_mutex(t_info *info);
int		init_philo(t_info *info, t_philo **philo);
int		init_thread(t_info *info, t_philo *philo);

/* philo.c */
void	new_sleep(long long wait_time);
int		print_state(t_info *info, char *str, int id);
int		execute_philo(t_info *info, t_philo *philo);
void	check_all_philo(int i, t_info *info, t_philo *philo);

/* thread.c */
void	check_even_odd(int id);
void	*get_thread(void *philo);
int		execute_thread(t_info *info, t_philo *philo);
void	free_thread(t_info *info, t_philo *philo);
void	routine(t_info *info, t_philo *philo);

#endif