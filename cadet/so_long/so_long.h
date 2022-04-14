/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:02:09 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/14 16:29:29 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define KEY_PRESSED	2
# define KEY_RELEASED	3

# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2

typedef struct s_param
{
	int	x;
	int	y;
}	t_param;

typedef struct g_game
{
	int		x;
	int		y;
	char	*str;
}	t_game;

void	param_init(t_param *param);
void	map_reader(char *filename, t_game *game);

#endif