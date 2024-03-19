/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_ft_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:37:40 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/15 12:28:10 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static char	*ft_validate_map(t_map *map);
static void	validate_line(t_map *map, char *buf, size_t c_size);
static void	free_error(t_map *map, char *buf);

static void	count_lines_file(t_map *map, char *file)
{
	char	*temp;

	map->fd = open_file(file);
	temp = get_next_line(map->fd, 1);
	if (!temp)
		fail_temp(map->fd);
	while (temp)
	{
		map->rows++;
		free(temp);
		temp = get_next_line(map->fd, 1);
	}
	free(temp);
	close(map->fd);
}

void	ft_validate(char *map_name)
{
	t_map	map;
	char	*buffer;

	init_variable_map(&map);
	count_lines_file(&map, map_name);
	map.fd = open_file(map_name);
	buffer = ft_validate_map(&map);
	close(map.fd);
	ft_validate_elements(buffer, &map);
	map.matrix = ft_split(buffer, '\n');
	map.matrix_clone = ft_split(buffer, '\n');
	free(buffer);
	ft_validate_path(&map);
	if (init_game(&map))
	{
		free_matrix(map.matrix);
		ft_error("It was not possible to init the game!\n", NULL);
	}
}

static char	*ft_validate_map(t_map *map)
{
	char	*buffer;
	size_t	col_size;

	buffer = NULL;
	map->temp = get_next_line(map->fd, 1);
	if (!map->temp)
		fail_temp(map->fd);
	col_size = ft_strlen(map->temp);
	map->cols = col_size - 1;
	while (map->temp)
	{
		validate_line(map, buffer, col_size);
		buffer = ft_strjoin_gnl(buffer, map->temp);
		free(map->temp);
		map->temp = get_next_line(map->fd, 1);
	}
	free(map->temp);
	return (buffer);
}

static void	validate_line(t_map *map, char *buf, size_t c_size)
{
	static int	time;

	if (check_proportion(map, c_size) || check_walls(map, c_size, time))
		free_error(map, buf);
	time++;
}

static void	free_error(t_map *map, char *buf)
{
	get_next_line(map->fd, 0);
	free(map->temp);
	if (buf)
		free(buf);
	close(map->fd);
	exit(EXIT_FAILURE);
}
