/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ft_utils_validate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:51:30 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/20 06:17:58 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_error(char *msg, char *buffer)
{
	if (buffer)
		free(buffer);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	fail_temp(int fd)
{
	close(fd);
	ft_error("Error\nThis file is empty!\n", NULL);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0666);
	if (fd == -1)
		ft_error("Error\nIt was no possible to open the map!\n", NULL);
	return (fd);
}

void	init_variable_map(t_map *map)
{
	map->start = 0;
	map->exit = 0;
	map->collectibles = 0;
	map->rows = 0;
	map->cols = 0;
	map->matrix = NULL;
	map->matrix_clone = NULL;
	map->player_x = 0;
	map->player_y = 0;
	map->count_moves = 0;
	map->temp = NULL;
	map->mlx = NULL;
	map->bg_sprit = NULL;
	map->wall_sprit = NULL;
	map->exit_sprit = NULL;
	map->player_sprit = NULL;
	map->collectibles_sprit = NULL;
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
