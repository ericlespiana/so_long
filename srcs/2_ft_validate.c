/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_ft_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:37:40 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 09:08:35 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	free_error(t_map *map, char *tmp, char *buf);
static char	*ft_validate_proportion(t_map *map, char *temp);
static void	validate_line(char *tmp, t_map *map, char *buf, size_t c_size);

void	ft_validate(char *map_name)
{
	t_map	map;
	char	*temp;
	char	*buffer;

	init_variable_map(&map);
	map.fd = open_file(map_name);
	temp = get_next_line(map.fd, 1);
	if (!temp)
		fail_temp(map.fd);
	buffer = ft_validate_proportion(&map, temp);
	free(buffer);
	close(map.fd);
}

static char	*ft_validate_proportion(t_map *map, char *temp)
{
	char	*buffer;
	size_t	col_size;

	buffer = NULL;
	col_size = ft_strlen(temp);
	while (temp)
	{
		if (!ft_strchr(temp, '\n'))
			--col_size;
		validate_line(temp, map, buffer, col_size);
		buffer = ft_strjoin_gnl(buffer, temp);
		free(temp);
		temp = get_next_line(map->fd, 1);
	}
	free(temp);
	return (buffer);
}

static void	validate_line(char *tmp, t_map *map, char *buf, size_t c_size)
{
	if (check_proportion(tmp, c_size) || check_walls(tmp, c_size)
		|| check_invalid_char(tmp))
		free_error(map, tmp, buf);
}

static void	free_error(t_map *map, char *tmp, char *buf)
{
	get_next_line(map->fd, 0);
	free(tmp);
	if (buf)
		free(buf);
	close(map->fd);
	ft_error("Error\nYour file is not sourrounded by 1 \
or it is out of proportion!\n");
}
