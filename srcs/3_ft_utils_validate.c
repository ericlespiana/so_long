/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ft_utils_validate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:51:30 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 10:41:25 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	fail_temp(int fd)
{
	close(fd);
	ft_error("Error\nThis file is empty!\n");
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0666);
	if (fd == -1)
		ft_error("Error\nIt was no possible to open the map!\n");
	return (fd);
}

void	init_variable_map(t_map *map)
{
	map->start = 0;
	map->exit = 0;
	map->collectibles = 0;
}
