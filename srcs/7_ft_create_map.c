/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_ft_create_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:28:07 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/20 03:57:54 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

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
	mlx_image_to_window(game->mlx, game->player_sprit->img, y, x);
}

void	create_map(t_map *game)
{
	int	l;
	int	c;
	int	x;
	int	y;

	l = 0;
	while (game->matrix[l])
	{
		c = 0;
		while (game->matrix[l][c])
		{
			x = c * IMG_SIZE;
			y = l * IMG_SIZE;
			mlx_image_to_window(game->mlx, game->bg_sprit->img, x, y);
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
}
