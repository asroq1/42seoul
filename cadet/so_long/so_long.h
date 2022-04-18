/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:02:09 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/18 16:45:03 by hyunjung         ###   ########.fr       */
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

typedef struct s_img
{
	int		img_width;
	int		img_height;
	void	*dest;
	void	*obj;
	void	*robot;
	void	*road;
	void	*wall;

}	t_img;

typedef struct s_game
{	
	void	*mlx;
	void	*window;
	int		x;
	int		y;
	char	*str;
	t_img	img;
	int		all_col;
	int		col_cnt;
}	t_game;

void	game_init(t_game *game);
void	get_map(char *filename, t_game *game);
void	put_map(t_game *game, int width, int height);
void	set_map(t_game *game);
t_img	get_image(void *mlx);
#endif