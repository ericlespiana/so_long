/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 02:50:37 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/07 17:26:04 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "libft.h"
# include <fcntl.h>

typedef struct s_maps
{
	int		fd;
	int		start;
	int		exit;
	int		collectibles;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	char	*temp;
	char	**matrix;
	char	**matrix_clone;
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

# define LIMIT_ARGS 2
# define TRUE 1
# define FALSE 0
# define EXIT_ERROR "Error\nYour map must have one and only one exit!\n"
# define COLLEC_ERROR "Error\nYour map must have at least one collectibles!\n"
# define PLAYER_ERROR "Error\nYour map must have one and only one player!\n"

#endif
