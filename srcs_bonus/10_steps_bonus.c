/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_steps_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:41:58 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/26 18:28:36 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	update_sprite(t_map *game, char axle, char operation)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
			game->player_sprit[i][j++]->img->enabled = 0;
		i++;
	}
	if (axle == 'y' && operation == '-')
		game->player_sprit[1][0]->img->enabled = 1;
	else if (axle == 'y' && operation == '+')
		game->player_sprit[0][0]->img->enabled = 1;
	else if (axle == 'x' && operation == '-')
		game->player_sprit[2][0]->img->enabled = 1;
	else if (axle == 'x' && operation == '+')
		game->player_sprit[3][0]->img->enabled = 1;
}

void	moove_player(t_map *game, char axle, char operation)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (axle == 'y' && operation == '-')
				game->player_sprit[i][j++]->img->instances[0].y -= 64;
			else if (axle == 'y' && operation == '+')
				game->player_sprit[i][j++]->img->instances[0].y += 64;
			else if (axle == 'x' && operation == '-')
				game->player_sprit[i][j++]->img->instances[0].x -= 64;
			else
				game->player_sprit[i][j++]->img->instances[0].x += 64;
		}
		i++;
	}
}

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
