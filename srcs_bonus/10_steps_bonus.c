/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_update_steps_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:41:58 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/26 11:46:29 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	updt_steps(t_map *game)
{
	char	*steps;

	steps = ft_itoa(game->count_moves);
	if (game->steps)
		mlx_delete_image(game->mlx, game->steps);
	game->steps = mlx_put_string(game->mlx, steps, 60, 0);
	free(steps);
}

void	put_step_text(t_map *game)
{
	game->text_step = mlx_put_string(game->mlx, "Steps:", 0, 0);
	updt_steps(game);
}
