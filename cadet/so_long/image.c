/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:27:52 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/27 13:02:54 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_img	get_image(void *mlx)
{
	t_img	img;
	img.robot = mlx_xpm_file_to_image(mlx, "./images/robot.xpm", &img.img_width, &img.img_height);
	img.dest = mlx_xpm_file_to_image(mlx, "./images/dest.xpm", &img.img_width, &img.img_height);
	img.road = mlx_xpm_file_to_image(mlx, "./images/road.xpm", &img.img_width, &img.img_height);
	img.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img.img_width, &img.img_height);
	img.obj = mlx_xpm_file_to_image(mlx, "./images/obj.xpm", &img.img_width, &img.img_height);
	return (img);
}
