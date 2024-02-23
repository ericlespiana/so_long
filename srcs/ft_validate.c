/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:37:40 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/23 08:44:08 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

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
	buffer = ft_strdup("");
	while (temp)
	{
		if (ft_strlen(temp) != column_size)
		{
			free(buffer);
			free(temp);
			ft_error(ERROR_COLUMN);
		}
		buffer = ft_strjoin(buffer, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	ft_printf("%s", buffer);
}

void	ft_validate(char *map_name)
{
	t_map	map;

	map.fd = open(map_name, O_RDONLY, 0666);
	ft_validate_proportion(map.fd, &map);
}
