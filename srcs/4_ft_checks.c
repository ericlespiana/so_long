/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:53:55 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 09:12:41 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	check_proportion(char *tmp, size_t c_size)
{
	if (c_size != ft_strlen(tmp))
		return (1);
	return (0);
}

int	check_walls(char *tmp, size_t c_size)
{
	static int	times;
	int			i;

	i = 0;
	if (times == 0 || !ft_strchr(tmp, '\n'))
	{
		while (tmp[i] && tmp[i] == '1')
			i++;
		if (tmp[i] != '\n' && tmp[i] != '\0')
			return (1);
		times = 1;
	}
	else if (tmp[0] != '1' || tmp[c_size - 2] != '1')
		return (1);
	return (0);
}

int	check_invalid_char(char *tmp)
{
	(void)tmp;
	return (0);
}
