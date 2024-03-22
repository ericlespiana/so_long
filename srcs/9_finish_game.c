/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_finish_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:53:38 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/21 23:36:18 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	free_sprite(t_map *game, t_sprite *sprite)
{
	mlx_delete_texture(sprite->texture);
	mlx_delete_image(game->mlx, sprite->img);
	free(sprite);
}

void	finish_game(t_map *game)
{
	free_matrix(game->matrix);
	free_sprite(game, game->bg_sprit);
	free_sprite(game, game->player_sprit);
	free_sprite(game, game->collectibles_sprit);
	free_sprite(game, game->exit_sprit);
	free_sprite(game, game->wall_sprit);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
