/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:24:01 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/22 12:06:23 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	key_w(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
	}
	if (game->str[i - game->x] == 'C')
	{
		game->obj_cnt++;
	}
	if (game->str[i - game->x] == 'E' && game->total_obj == game->obj_cnt)
		end_game(game);
	else if (game->str[i - game->x] != '1' && game->str[i - game->x] != 'E')
	{
		game->str[i] = '0';
		game->str[i - game->x] = 'P';
		game->step_cnt++;
		set_map(game);
	}
}

void	key_s(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
	}
	if (game->str[i + game->x] == 'C')
	{
		game->obj_cnt++;
	}
	if (game->str[i + game->x] == 'E' && game->total_obj == game->obj_cnt)
		end_game(game);
	else if (game->str[i + game->x] != '1' && game->str[i + game->x] != 'E')
	{
		game->str[i] = '0';
		game->str[i + game->x] = 'P';
		game->step_cnt++;
		set_map(game);
	}
}

void	key_a(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
	}
	if (game->str[i - 1] == 'C')
	{
		game->obj_cnt++;
	}
	if (game->str[i - 1] == 'E' && game->total_obj == game->obj_cnt)
		end_game(game);
	else if (game->str[i - 1] != '1' && game->str[i - 1] != 'E')
	{
		game->str[i] = '0';
		game->str[i - 1] = 'P';
		game->step_cnt++;
		set_map(game);
	}
}

void	key_d(t_game *game)
{
	int	i;

	i = 1;
	while (i++ < ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
	}
	if (game->str[i + 1] == 'C')
	{
		game->obj_cnt++;
	}
	if (game->str[i + 1] == 'E' && game->total_obj == game->obj_cnt)
		end_game(game);
	else if (game->str[i + 1] != '1' && game->str[i + 1] != 'E')
	{
		game->str[i] = '0';
		game->str[i + 1] = 'P';
		game->step_cnt++;
		set_map(game);
	}
}

void	end_game(t_game *game)
{
	game->step_cnt++;
	printf("clear ! you've walked %d steps \n", game->step_cnt);
	exit(EXIT_SUCCESS);
}
