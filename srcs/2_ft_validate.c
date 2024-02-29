/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_ft_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:37:40 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 11:55:25 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	free_error(int fd, char *tmp, char *buf);
static char	*ft_validate_map(int fd, char *temp);
static void	validate_line(char *tmp, int fd, char *buf, size_t c_size);

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
	buffer = ft_validate_map(map.fd, temp);
	close(map.fd);
	ft_validate_path(buffer, &map);
	free(buffer);
}

static char	*ft_validate_map(int fd, char *temp)
{
	char	*buffer;
	size_t	col_size;

	buffer = NULL;
	col_size = ft_strlen(temp);
	while (temp)
	{
		if (!ft_strchr(temp, '\n'))
			--col_size;
		validate_line(temp, fd, buffer, col_size);
		buffer = ft_strjoin_gnl(buffer, temp);
		free(temp);
		temp = get_next_line(fd, 1);
	}
	free(temp);
	return (buffer);
}

static void	validate_line(char *tmp, int fd, char *buf, size_t c_size)
{
	static int	time;

	if (check_proportion(tmp, c_size) || check_walls(tmp, c_size, time))
		free_error(fd, tmp, buf);
	time = 1;
}

static void	free_error(int fd, char *tmp, char *buf)
{
	get_next_line(fd, 0);
	free(tmp);
	if (buf)
		free(buf);
	close(fd);
	exit(EXIT_FAILURE);
}
