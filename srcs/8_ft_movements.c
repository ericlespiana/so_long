/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_ft_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 06:11:41 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/21 19:47:54 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	check_won(t_map *game)
{
	if (game->rest_collectibles == 0)
	{
		if (game->exit_sprit->img->enabled == FALSE)
			game->exit_sprit->img->enabled = TRUE;
	}
	if (game->exit_sprit->img->enabled &&
		game->player_sprit->img->instances[0].x
		== game->exit_sprit->img->instances[0].x
		&& game->player_sprit->img->instances[0].y
		== game->exit_sprit->img->instances[0].y)
		{
			mlx_close_window(game->mlx);
		}
}

void	upt_collectible(t_map *game)
{
	int	i;

	i = 0;
	while (i < game->collectibles)
	{
		if (game->player_sprit->img->instances[0].x
			== game->collectibles_sprit->img->instances[i].x
			&& game->player_sprit->img->instances[0].y
			== game->collectibles_sprit->img->instances[i].y)
		{
			if (game->collectibles_sprit->img->instances[i].enabled)
			{
				game->rest_collectibles--;
				game->collectibles_sprit->img->instances[i].enabled = FALSE;
			}
		}
		i++;
	}
}

static void	validate_y(t_map *game, char operation)
{
	if (operation == '-')
	{
		if (game->matrix[game->player_x - 1][game->player_y] != '1')
		{
			//ft_printf("Move: %d\n", ++game->count_moves);
			game->player_sprit->img->instances[0].y -= 64;
			game->player_x--;
		}
	}
	else
	{
		if (game->matrix[game->player_x + 1][game->player_y] != '1')
		{
			//ft_printf("Move: %d\n", ++game->count_moves);
			game->player_sprit->img->instances[0].y += 64;
			game->player_x++;
		}
	}
}

static void	validate_x(t_map *game, char operation)
{
	if (operation == '-')
	{
		if (game->matrix[game->player_x][game->player_y - 1] != '1')
		{
			//ft_printf("Move: %d\n", ++game->count_moves);
			game->player_sprit->img->instances[0].x -= 64;
			game->player_y--;
		}
	}
	else
	{
		if (game->matrix[game->player_x][game->player_y + 1] != '1')
		{
			//ft_printf("Move: %d\n", ++game->count_moves);
			game->player_sprit->img->instances[0].x += 64;
			game->player_y++;
		}
	}
}

void	validate_move(t_map *game, char direction, char op)
{
	if (direction == 'y')
		validate_y(game, op);
	else if (direction == 'x')
		validate_x(game, op);
	if (game->rest_collectibles == 0)
	{
		if (game->exit_sprit->img->instances[0].enabled == FALSE)
			game->exit_sprit->img->instances[0].enabled = TRUE;
		game->rest_collectibles = -1;
	}
}
