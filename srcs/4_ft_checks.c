/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:53:55 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 10:29:54 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static int	check_invalid_char(char *tmp);

int	check_proportion(char *tmp, size_t c_size)
{
	if (c_size != ft_strlen(tmp))
		return (1);
	return (0);
}

int	check_walls(char *tmp, size_t c_size, int time)
{
	int	i;

	i = 0;
	if (time == 0 || !ft_strchr(tmp, '\n'))
	{
		while (tmp[i] && tmp[i] == '1')
			i++;
		if (tmp[i] != '\n' && tmp[i] != '\0')
			return (1);
		else
			return (0);
	}
	else if (tmp[0] != '1' || tmp[c_size - 2] != '1')
		return (1);
	else
		return (check_invalid_char(tmp));
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
			ft_putstr_fd("Invalid char in your map!\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
