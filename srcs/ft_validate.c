/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:37:40 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/27 06:45:47 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	check_one(char *temp, t_map *map, char *buffer)
{
	int	i;

	i = 0;
	while (temp[i] && temp[i] == '1')
		i++;
	if (temp[i] != '\n' && temp[i] != '\0')
	{
		free(temp);
		if (buffer)
			free(buffer);
		close(map->fd);
		ft_error(ERROR_WALL);
	}
}

static void	ft_validate_proportion(int fd, t_map *map)
{
	char	*temp;
	char	*buffer;
	size_t	column_size;

	(void)map;
	temp = get_next_line(fd);
	if (!temp)
		ft_error(READ_ERROR);
	column_size = ft_strlen(temp);
	buffer = NULL;
	check_one(temp, map, buffer);
	while (temp)
	{
		if (!ft_strchr(temp, '\n'))
		{
			column_size--;
			check_one(temp, map, buffer);
		}
		if (ft_strlen(temp) != column_size)
		{
			free(buffer);
			free(temp);
			ft_error(ERROR_COLUMN);
		}
		buffer = ft_strjoin_gnl(buffer, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
}

void	ft_validate(char *map_name)
{
	t_map	map;

	map.fd = open(map_name, O_RDONLY, 0666);
	ft_validate_proportion(map.fd, &map);
	close(map.fd);
}
