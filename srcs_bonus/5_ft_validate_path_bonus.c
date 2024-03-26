/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ft_validate_path_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:46:12 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/22 05:35:12 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

static void	find_position_player(t_map *map);
static void	ft_floodfill(t_map *map, int pos_x, int pos_y);
static int	ft_check_invalid_map(char **clone);
void		ft_validate_elements(char *buffer, t_map *map);

void	ft_validate_path(t_map *map)
{
	find_position_player(map);
	ft_floodfill(map, map->player_x, map->player_y);
	if (ft_check_invalid_map(map->matrix_clone))
	{
		free_matrix(map->matrix_clone);
		free_matrix(map->matrix);
		ft_error("Error\nInvalid MAP! Please provide a possible path!\n", NULL);
	}
	free_matrix(map->matrix_clone);
}

void	ft_validate_elements(char *buffer, t_map *map)
{
	int	i;

	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == 'E')
			map->exit++;
		else if (buffer[i] == 'C')
			map->collectibles++;
		else if (buffer[i] == 'P')
			map->start++;
	}
	if (map->exit != 1)
		ft_error(EXIT_ERROR, buffer);
	else if (map->start != 1)
		ft_error(PLAYER_ERROR, buffer);
	else if (map->collectibles < 1)
		ft_error(COLLEC_ERROR, buffer);
	map->rest_collectibles = map->collectibles;
}

static void	find_position_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->matrix_clone[i])
	{
		j = 0;
		while (map->matrix_clone[i][j])
		{
			if (map->matrix_clone[i][j] == 'P')
			{
				map->player_x = i;
				map->player_y = j;
				break ;
			}
			j++;
		}
		if (map->player_x != 0)
			break ;
		i++;
	}
}

static void	ft_floodfill(t_map *map, int pos_x, int pos_y)
{
	if (pos_x < 1 || pos_x > map->rows || pos_y < 1 || pos_y > map->cols
		|| map->matrix_clone[pos_x][pos_y] == '1')
		return ;
	map->matrix_clone[pos_x][pos_y] = '1';
	ft_floodfill(map, pos_x - 1, pos_y);
	ft_floodfill(map, pos_x + 1, pos_y);
	ft_floodfill(map, pos_x, pos_y - 1);
	ft_floodfill(map, pos_x, pos_y + 1);
}

static int	ft_check_invalid_map(char **clone)
{
	int	i;

	i = 0;
	while (*clone)
	{
		if (ft_strchr(*clone, 'C') || ft_strchr(*clone, 'E'))
			return (TRUE);
		clone++;
	}
	return (FALSE);
}
