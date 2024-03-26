/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_checks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:53:55 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/22 05:35:08 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

static int	check_invalid_char(char *tmp);

int	check_proportion(t_map *map, size_t c_size)
{
	if (!ft_strchr(map->temp, '\n'))
		c_size--;
	if (c_size != ft_strlen(map->temp) || map->rows == 1)
	{
		ft_putstr_fd("Error\nYour map is not rectangle\n", 2);
		return (TRUE);
	}
	return (FALSE);
}

int	check_walls(t_map *map, size_t c_size, int time)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (time == 0 || time == map->rows - 1)
	{
		while (map->temp[i] && map->temp[i] == '1')
			i++;
		if (map->temp[i] != '\n' && map->temp[i] != '\0')
			flag = 1;
	}
	else if (map->temp[0] != '1' || map->temp[c_size - 2] != '1')
		flag = 1;
	else
		return (check_invalid_char(map->temp));
	if (flag)
	{
		ft_putstr_fd("Error\nMap don't surrounded by 1\n", 2);
		return (TRUE);
	}
	return (FALSE);
}

static int	check_invalid_char(char *tmp)
{
	int	i;

	i = 1;
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		if (tmp[i] != '0' && tmp[i] != '1' && tmp[i] != 'C'
			&& tmp[i] != 'E' && tmp[i] != 'P')
		{
			ft_putstr_fd("Error\nInvalid char in your map!\n", 2);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
