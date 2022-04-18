/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:27:52 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/18 15:42:29 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_img	get_image(void *mlx)
{
	t_img image;

	image.robot = mlx_xpm_file_to_image(mlx, "./images/robot.xpm", &image.img_width, &image.img_height);
	image.dest = mlx_xpm_file_to_image(mlx, "./images/dest.xpm", &image.img_width, &image.img_height);
	image.road = mlx_xpm_file_to_image(mlx, "./images/road.xpm", &image.img_width, &image.img_height);
	image.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &image.img_width, &image.img_height);
	image.obj = mlx_xpm_file_to_image(mlx, "./images/obj.xpm", &image.img_width, &image.img_height);
	return (image);
}
