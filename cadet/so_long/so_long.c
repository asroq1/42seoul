/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:34:54 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/14 16:32:48 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int	on_key_press(int evt, t_param *param)
{
	if (evt == W)
	{
		param->y++;
	}
	else if (evt == S)
	{
		param->y--;
	}
	else if (evt == A)
	{
		param->x--;
	}
	else if (evt == D)
	{
		param->x++;
	}
	else if (evt == ESC)
	{
		exit(EXIT_SUCCESS);
	}
	printf("x : %d, y : %d \n", param->x, param->y);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("map error");
	}
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	int		img_width;
	int		img_height;
	t_param	param;
	t_game  game;

	map_reader(argv[1], &game);
	param_init(&param);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello World");
	img = mlx_xpm_file_to_image(mlx_ptr, "./images/robot.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx_ptr, "./images/wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx_ptr, "./images/land.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx_ptr, "./images/tree.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx_ptr, "./images/dest.xpm", &img_width, &img_height);
	
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img2, 64, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img3, 128, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img4, 0, 64);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img5, 64, 64);
	mlx_hook(win_ptr, KEY_RELEASED, 0, &on_key_press, &param);
	mlx_loop(mlx_ptr);
	return (0);
}
