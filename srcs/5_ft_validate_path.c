/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ft_validate_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:46:12 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/01 08:26:37 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_validate_elements(char *buffer, t_map *map);
void	ft_validate_path(t_map *map);

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

void	ft_validate_path(t_map *map)
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
	ft_floodfill(map, map->player_x, map->player_y);
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
}
