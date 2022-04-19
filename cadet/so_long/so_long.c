/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:34:54 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/19 17:11:32 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game, char *map)
{
	game->mlx = mlx_init();
	game->img = get_image(game->mlx);
	download_map(map, game);
	game->win = mlx_new_window(game->mlx, game->x * 64, game->y * 64, "so_");
	set_map(game);
}

int	on_key_press(int evt, t_game *game)
{
	if (evt == W)
	{
		key_w(game);
	}
	else if (evt == S)
	{
		key_s(game);
	}
	else if (evt == A)
	{
		key_a(game);
	}
	else if (evt == D)
	{
		key_d(game);
	}
	else if (evt == ESC)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.obj_cnt = 0;
	game.total_obj = 0;
	if (argc != 2)
	{
		printf("map error");
	}
	start_game(&game, argv[1]);
	mlx_hook(game.win, KEY_RELEASED, 0, &on_key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
