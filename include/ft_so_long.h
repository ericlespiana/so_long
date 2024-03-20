/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 02:50:37 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/20 06:17:42 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>

typedef struct s_sprites
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
}	t_sprite;

typedef struct s_maps
{
	int				fd;
	int				start;
	int				exit;
	int				collectibles;
	int				rows;
	int				cols;
	int				player_x;
	int				player_y;
	int				count_moves;
	char			*temp;
	char			**matrix;
	char			**matrix_clone;
	mlx_t			*mlx;
	t_sprite		*bg_sprit;
	t_sprite		*wall_sprit;
	t_sprite		*exit_sprit;
	t_sprite		*player_sprit;
	t_sprite		*collectibles_sprit;
}	t_map;

void		ft_parse_arguments(int argc, char *map_name);
void		ft_validate(char *map_name);
void		init_variable_map(t_map *map);
void		ft_error(char *msg, char *buffer);
void		fail_temp(int fd);
int			open_file(char *file);
int			check_proportion(t_map *map, size_t c_size);
int			check_walls(t_map *map, size_t c_size, int time);
void		ft_validate_elements(char *buffer, t_map *map);
void		ft_validate_path(t_map *map);
void		free_matrix(char **matrix);
int			init_game(t_map *game);
void		create_map(t_map *game);
void		validate_move(t_map *game, char direction, char op);

# define LIMIT_ARGS 2
# define TRUE 1
# define FALSE 0
# define EXIT_ERROR "Error\nYour map must have one and only one exit!\n"
# define COLLEC_ERROR "Error\nYour map must have at least one collectibles!\n"
# define PLAYER_ERROR "Error\nYour map must have one and only one player!\n"
# define WIDTH 1920
# define HEIGTH 1080
# define IMG_SIZE 64

#endif
