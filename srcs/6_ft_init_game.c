/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ft_init_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:47:40 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/19 20:25:19 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static t_sprite	*generate_imgs(t_map *game, char *path)
{
	t_sprite	*sprite;

	sprite = ft_calloc(1, sizeof(t_sprite*));
	if (!sprite)
		return (NULL);
	sprite->texture = mlx_load_png(path);
	if (!sprite->texture)
	{
		free_matrix(game->matrix);
		ft_error("Error to create the texture\n", NULL);
	}
	sprite->img = mlx_texture_to_image(game->mlx, sprite->texture);
	if (!sprite->img)
	{
		free_matrix(game->matrix);
		ft_error("Error to create the image\n", NULL);
	}
	return (sprite);
}

static void	init_sprits(t_map *game)
{
	game->bg_sprit = generate_imgs(game, "textures/bg0.png");
	game->wall_sprit = generate_imgs(game, "textures/wall0.png");
	game->exit_sprit = generate_imgs(game, "textures/exit.png");
	game->player_sprit = generate_imgs(game, "textures/player.png");
	game->collectibles_sprit = generate_imgs(game, "textures/collectable0.png");	
}

int	init_game(t_map *game)
{
	game->mlx = mlx_init(WIDTH, HEIGTH, "So long", true);
	if (!game->mlx)
		return (1);
	init_sprits(game);h
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	
	return (0);
}
