/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ft_init_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:47:40 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/14 04:10:43 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	init_game(t_map *game)
{
	(void)game;
	mlx_t*	screen;
	mlx_texture_t	*texture;
	mlx_image_t *img;


	screen = mlx_init(WIDTH, HEIGTH, "GAME", true);
	if (!screen)
		return (1);
	texture = mlx_load_png("textures/background.png");
	img = mlx_texture_to_image(screen, texture);
	mlx_image_to_window(screen, img, 10, 10);

	mlx_loop(screen);
	mlx_terminate(screen);
	
	return (0);
}