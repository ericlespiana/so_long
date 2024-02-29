/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:53:55 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 12:01:15 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static int	check_invalid_char(char *tmp);

int	check_proportion(char *tmp, size_t c_size)
{
	if (c_size != ft_strlen(tmp))
	{
		ft_putstr_fd("Error\nInvalid proportion!\n", 2);
		return (TRUE);
	}
	return (FALSE);
}

int	check_walls(char *tmp, size_t c_size, int time)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (time == 0 || !ft_strchr(tmp, '\n'))
	{
		while (tmp[i] && tmp[i] == '1')
			i++;
		if (tmp[i] != '\n' && tmp[i] != '\0')
			flag = 1;
	}
	else if (tmp[0] != '1' || tmp[c_size - 2] != '1')
		flag = 1;
	else
		return (check_invalid_char(tmp));
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
