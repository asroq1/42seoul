/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:21:56 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/19 12:08:30 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	download_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		printf("File open failed \n");
	}
	line = get_next_line(fd);
	game->y = 0;
	game->x = ft_strlen(line) - 1;
	game->str = utils_strdup(line);
	free(line);
	while (line != 0)
	{
		game->y++;
		line = get_next_line(fd);
		if (line != 0)
		{
			game->str = utils_strjoin(game->str, line);
		}
	}
	close(fd);
	printf("%s \n", game->str);
}

void	put_map(t_game *g, int w, int h)
{
	if (g->str[g->x * h + w] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 64, h * 64);
	}
	else if (g->str[g->x * h + w] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.obj, w * 64, h * 64);
	}
	else if (g->str[g->x * h + w] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.dest, w * 64, h * 64);
	}
	else if (g->str[g->x * h + w] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.robot, w * 64, h * 64);
	}
	else if (g->str[g->x * h + w] == '0')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.road, w * 64, h * 64);
	}
}

// void	set_map(t_game *game)
// {
// 	int	width;
// 	int	height;

// 	height = 0;
// 	while (height < game->y)
// 	{
// 		width = 0;
// 		while (width < game->x)
// 		{
// 			put_map(game, width, height);
// 			width++;
// 		}
// 		printf("width : %d", width);
// 		height++;
// 	}
// 	printf("height : %d", height);
// }


void	set_map(t_game *game)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < game->y)
	{
		wid = 0;
		while (wid < game->x)
		{
			put_map(game, wid, hei);
			wid++;
		}
		printf("width : %d\n", wid);
		hei++;
	}
	printf("height : %d\n", hei);
}
