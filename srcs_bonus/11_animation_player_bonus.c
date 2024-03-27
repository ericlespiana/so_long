/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_animation_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:41:58 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/26 17:57:59 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

static void	fill_sprit(t_map *game, int row)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (game->player_sprit[row][0]->img->enabled == 1)
		flag = 1;
	else if (game->player_sprit[row][1]->img->enabled == 1)
		flag = 2;
	else if (game->player_sprit[row][2]->img->enabled == 1)
		flag = 3;
	else if (game->player_sprit[row][3]->img->enabled == 1)
		flag = 0;
	while (i <= 3)
		game->player_sprit[row][i++]->img->enabled = 0;
	game->player_sprit[row][flag]->img->enabled = 1;
}

void	ft_animation(t_map *game)
{
	if (game->side == '^')
		fill_sprit(game, 1);
	if (game->side == '<')
		fill_sprit(game, 2);
	if (game->side == '>')
		fill_sprit(game, 3);
	if (game->side == 'v' || game->side == 0)
		fill_sprit(game, 0);
}
