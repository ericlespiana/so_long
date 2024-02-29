/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ft_validate_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:46:12 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 12:00:02 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_validate_path(char *buffer, t_map *map)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'E')
			map->exit++;
		else if (buffer[i] == 'C')
			map->collectibles++;
		else if (buffer[i] == 'P')
			map->start++;
		i++;
	}
	if (map->exit != 1)
		ft_error(EXIT_ERROR, buffer);
	else if (map->start != 1)
		ft_error(PLAYER_ERROR, buffer);
	else if (map->collectibles < 1)
		ft_error(COLLEC_ERROR, buffer);
}
