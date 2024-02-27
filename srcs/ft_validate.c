/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:37:40 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/27 10:19:17 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	init_variable_map(t_map *map)
{
	map->start = 0;
	map->exit = 0;
	map->collectibles = 0;
}
static void	ft_validate_proportion(int fd, t_map *map);
static void	check_one_and_size(char *tmp, t_map *map, char *buf, size_t c_size);

//Funcão principal desse arquivo

void	ft_validate(char *map_name)
{
	t_map	map;

	init_variable_map(&map);
	map.fd = open(map_name, O_RDONLY, 0666);
	if (map.fd == -1)
		ft_error("Error to open map!\n");
	ft_validate_proportion(map.fd, &map);
	close(map.fd);
}

static void	ft_validate_proportion(int fd, t_map *map)
{
	char	*temp;
	char	*buffer;
	size_t	column_size;

	temp = get_next_line(fd, 1);
	if (!temp)
		ft_error("Error\nIt was no possible to read the file descriptor\n");
	buffer = NULL;
	column_size = ft_strlen(temp);
	check_one_and_size(temp, map, buffer, column_size);
	while (temp)
	{
		if (!ft_strchr(temp, '\n'))
		{
			column_size--;
			check_one_and_size(temp, map, buffer, column_size);
		}
		if (ft_strlen(temp) != column_size)
			check_one_and_size(temp, map, buffer, column_size);
		buffer = ft_strjoin_gnl(buffer, temp);
		free(temp);
		temp = get_next_line(fd, 1);
	}
	free(temp);
	free(buffer);
}

static void	check_one_and_size(char *tmp, t_map *map, char *buf, size_t c_size)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i] == '1')
		i++;
	if ((tmp[i] != '\n' && tmp[i] != '\0') || ft_strlen(tmp) != c_size)
	{
		get_next_line(map->fd, 0);
		free(tmp);
		if (buf)
			free(buf);
		close(map->fd);
		ft_error("Error\nMap don't surrounded by 1\n");
	}
}
