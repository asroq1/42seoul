/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:34:54 by hyunjung          #+#    #+#             */
/*   Updated: 2022/05/02 13:59:41 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	start_game(t_game *game, char *map)
{
	game->mlx = mlx_init();
	game->img = get_image(game->mlx);
	download_map(map, game);
	validate_map(game);
	game->win = mlx_new_window(game->mlx, game->x * 32, game->y * 32, "so_");
	set_map(game);
}

int	stop_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
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
	printf("%d Step!\n", game->step_cnt);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		occur_error();
	}
	game = malloc(sizeof(t_game));
	start_game(game, argv[1]);
	mlx_hook(game->win, KEY_RELEASED, 0, &on_key_press, game);
	mlx_hook(game->win, X_WINDOW_EXIT, 0, &stop_game, game);
	mlx_loop(game->mlx);
	return (0);
}
