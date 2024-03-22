/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ft_init_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:47:40 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/22 03:25:42 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static t_sprite	*generate_imgs(t_map *game, char *path)
{
	t_sprite	*sprite;

	sprite = ft_calloc(1, sizeof(t_sprite));
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
	mlx_resize_image(sprite->img, IMG_SIZE, IMG_SIZE);
	return (sprite);
}

static void	init_sprits(t_map *game)
{
	game->bg_sprit = generate_imgs(game, "textures/floor.png");
	game->wall_sprit = generate_imgs(game, "textures/wall.png");
	game->exit_sprit = generate_imgs(game, "textures/exit.png");
	game->player_sprit = generate_imgs(game, "textures/player_down_1.png");
	game->collectibles_sprit = generate_imgs(game, "textures/collectable0.png");
}

static void	hook_key_press(mlx_key_data_t key, t_map *game)
{
	if (key.key == MLX_KEY_ESCAPE)
		finish_game(game);
	else if ((key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		&& key.action == MLX_PRESS)
		validate_move(game, 'y', '-');
	else if ((key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		&& key.action == MLX_PRESS)
		validate_move(game, 'y', '+');
	else if ((key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
		&& key.action == MLX_PRESS)
		validate_move(game, 'x', '-');
	else if ((key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
		&& key.action == MLX_PRESS)
		validate_move(game, 'x', '+');
	upt_collectible(game);
	check_won(game);
}

int	init_game(t_map *game)
{
	int	max_columns;
	int	max_lines;

	max_columns = IMG_SIZE * game->cols;
	max_lines = IMG_SIZE * game->rows;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(max_columns, max_lines, "So long", true);
	if (!game->mlx)
		return (1);
	init_sprits(game);
	create_map(game);
	mlx_key_hook(game->mlx, (mlx_keyfunc)hook_key_press, game);
	mlx_loop(game->mlx);
	finish_game(game);
	return (0);
}
