/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:37:40 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/27 14:15:11 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	ft_validate_proportion(t_map *map, char *temp);
static void	check_one_and_size(char *tmp, t_map *map, char *buf, size_t c_size);

static void	init_variable_map(t_map *map)
{
	map->start = 0;
	map->exit = 0;
	map->collectibles = 0;
}

static void	free_error(t_map *map, char *tmp, char *buf)
{
	get_next_line(map->fd, 0);
	free(tmp);
	if (buf)
		free(buf);
	close(map->fd);
	ft_error("Error\nYour file is not sourroundet by \
or it is out of proportion!\n");
}

void	ft_validate(char *map_name)
{
	t_map	map;
	char	*temp;

	init_variable_map(&map);
	map.fd = open(map_name, O_RDONLY, 0666);
	if (map.fd == -1)
		ft_error("Error to open map!\n");
	temp = get_next_line(map.fd, 1);
	if (!temp)
	{
		close(map.fd);
		ft_error("Error\nThis file is empty!\n");
	}
	ft_validate_proportion(&map, temp);
	close(map.fd);
}

static void	ft_validate_proportion(t_map *map, char *temp)
{
	char	*buffer;
	size_t	col_size;

	buffer = NULL;
	col_size = ft_strlen(temp);
	while (temp)
	{
		if (!ft_strchr(temp, '\n'))
			--col_size;
		check_one_and_size(temp, map, buffer, col_size);
		buffer = ft_strjoin_gnl(buffer, temp);
		free(temp);
		temp = get_next_line(map->fd, 1);
	}
	free(temp);
	free(buffer);
}

static void	check_one_and_size(char *tmp, t_map *map, char *buf, size_t c_size)
{
	int			i;
	int			flag;
	static int	times;

	i = 0;
	flag = 0;
	if (times == 0 || !ft_strchr(tmp, '\n'))
	{
		while (tmp[i] && tmp[i] == '1')
			i++;
		if (tmp[i] != '\n' && tmp[i] != '\0')
			flag = 1;
	}
	if (c_size != ft_strlen(tmp))
		flag = 1;
	if (flag)
		free_error(map, tmp, buf);
}
