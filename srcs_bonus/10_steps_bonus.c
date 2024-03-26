/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_steps_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:41:58 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/26 13:45:53 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	updt_steps(t_map *game)
{
	char	*steps;

	steps = ft_itoa(game->count_moves);
	if (game->steps)
		mlx_delete_image(game->mlx, game->steps);
	game->steps = mlx_put_string(game->mlx, steps, 100, 20);
	free(steps);
}

void	put_step_text(t_map *game)
{
	mlx_resize_image(game->bg_count->img, 150, IMG_SIZE);
	mlx_image_to_window(game->mlx, game->bg_count->img, 0, 0);
	game->text_step = mlx_put_string(game->mlx, "Steps:", 40, 20);
	updt_steps(game);
}
