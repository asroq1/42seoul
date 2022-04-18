/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:34:54 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/18 17:24:59 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game, char *map)
{
	game->mlx = mlx_init();
	game->img = get_image(game->mlx);
	get_map(map, game);
	game->window = mlx_new_window(game->mlx, game->x * 64, game->y * 64, "so_long");
	set_map(game);
}
       
int	on_key_press(int evt, t_game *game)
{
	if (evt == W)
	{
		game->y++;
	}
	else if (evt == S)
	{
		game->y--;
	}
	else if (evt == A)
	{
		game->x--;
	}
	else if (evt == D)
	{
		game->x++;
	}
	else if (evt == ESC)
	{
		exit(EXIT_SUCCESS);
	}
	printf("x : %d, y : %d \n", game->x, game->y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("map error");
	}
	start_game(&game, argv[1]);
	mlx_hook(game.window, KEY_RELEASED, 0, &on_key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
