/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_ft_create_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:28:07 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/26 14:35:00 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

static void	put_wall(t_map *game, int c, int l)
{
	int	x;
	int	y;

	x = c * IMG_SIZE;
	y = l * IMG_SIZE;
	mlx_image_to_window(game->mlx, game->wall_sprit->img, x, y);
}

static void	put_exit(t_map *game, int c, int l)
{
	int	x;
	int	y;

	x = c * IMG_SIZE;
	y = l * IMG_SIZE;
	mlx_image_to_window(game->mlx, game->exit_sprit->img, x, y);
	game->exit_sprit->img->enabled = FALSE;
}

static void	put_collectible(t_map *game, int c, int l)
{
	int	x;
	int	y;

	x = c * IMG_SIZE;
	y = l * IMG_SIZE;
	mlx_image_to_window(game->mlx, game->collectibles_sprit->img, x, y);
}

static void	put_player(t_map *game)
{
	int	x;
	int	y;

	x = game->player_x * IMG_SIZE;
	y = game->player_y * IMG_SIZE;
	mlx_image_to_window(game->mlx, game->player_sprit[0]->img, y, x);
	mlx_image_to_window(game->mlx, game->player_sprit[1]->img, y, x);
	mlx_image_to_window(game->mlx, game->player_sprit[2]->img, y, x);
	mlx_image_to_window(game->mlx, game->player_sprit[3]->img, y, x);
	game->player_sprit[1]->img->enabled = 0;
	game->player_sprit[2]->img->enabled = 0;
	game->player_sprit[3]->img->enabled = 0;
}

void	create_map(t_map *game)
{
	int	l;
	int	c;

	l = 0;
	while (game->matrix[l])
	{
		c = 0;
		while (game->matrix[l][c])
		{
			mlx_image_to_window(game->mlx, game->bg_sprit->img, \
			c * IMG_SIZE, l * IMG_SIZE);
			if (game->matrix[l][c] == '1')
				put_wall(game, c, l);
			else if (game->matrix[l][c] == 'E')
				put_exit(game, c, l);
			else if (game->matrix[l][c] == 'C')
				put_collectible(game, c, l);
			c++;
		}
		l++;
	}
	put_player(game);
	put_step_text(game);
}
