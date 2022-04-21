/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:02:09 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/21 17:53:49 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_beta/mlx.h"
# include "./get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define KEY_PRESSED	2
# define KEY_RELEASED	3
# define X_WINDOW_EXIT	17

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
	int		step_cnt;
	int		obj_cnt;
	int		total_obj;
}	t_game;

/* so_long.c */
void	start_game(t_game *game, char *map);
int		stop_game(t_game *game);
int		on_key_press(int evt, t_game *game);

/* map.c */
t_img	get_image(void *mlx);
void	download_map(char *filename, t_game *game);
void	put_map(t_game *game, int width, int height);
void	set_map(t_game *game);

/* key.c */
void	key_w(t_game *game);
void	key_s(t_game *game);
void	key_d(t_game *game);
void	key_a(t_game *game);
void	end_game(t_game *game);

/* utils.c */
int		utils_strlcpy(char *dest, char *src, int length);
char	*utils_strjoin(char *s1, char *s2);
char	*utils_strdup(char *str);

/* error.c*/
void	occur_error(void);
void	validate_wall(t_game *game);
void	validate_rectangle(t_game *game);
void	validate_map(t_game *game);
void	validate_count(t_game *game);
#endif