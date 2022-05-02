/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:28:14 by hyunjung          #+#    #+#             */
/*   Updated: 2022/05/02 11:10:30 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	occur_error(void)
{
	perror("Error");
	exit(EXIT_SUCCESS);
}

void	validate_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->str))
	{
		if (i < game->x)
		{
			if (game->str[i] != '1')
				occur_error();
		}
		else if (i % game->x == 0 || i % game->x == i % game->x - 1)
		{
			if (game->str[i] != '1')
				occur_error();
		}
		else if (i > ft_strlen(game->str) - game->x)
		{
			if (game->str[i] != '1')
				occur_error();
		}
	i++;
	}
}

void	validate_count(t_game *game)
{
	int	i;
	int	end_point;
	int	player;

	i = 0;
	end_point = 0;
	player = 0;
	game->obj_cnt = 0;
	game->total_obj = 0;
	while (i++ < ft_strlen(game->str))
	{
		if (game->str[i] == 'E')
			end_point++;
		else if (game->str[i] == 'P')
			player++;
		else if (game->str[i] == 'C')
			game->total_obj++;
	}
	if (end_point == 0 || player == 0 || player > 1 || game->total_obj == 0)
		occur_error();
}

void	validate_rectangle(t_game *game)
{
	if (game->x * game->y != ft_strlen(game->str))
		occur_error();
}

void	validate_map(t_game *game)
{
	validate_rectangle(game);
	validate_wall(game);
	validate_count(game);
}
