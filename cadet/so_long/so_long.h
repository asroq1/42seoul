/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:02:09 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/19 16:46:39 by hyunjung         ###   ########.fr       */
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
	void	*win;
	int		x;
	int		y;
	char	*str;
	t_img	img;
	int		all_col;
	int		step_cnt;
	int		obj_cnt;
	int		total_obj;
}	t_game;

void	game_init(t_game *game);
void	download_map(char *filename, t_game *game);
void	put_map(t_game *game, int width, int height);
void	set_map(t_game *game);
t_img	get_image(void *mlx);
int		utils_strlcpy(char *dest, char *src, int length);
char	*utils_strjoin(char *s1, char *s2);
char	*utils_strdup(char *str);

/* key.c */ 
void	key_w(t_game *game);
void	key_s(t_game *game);
void	key_d(t_game *game);
void	key_a(t_game *game);

#endif