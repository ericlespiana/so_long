/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ft_parse_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:01:55 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 10:39:21 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static int	validate_extension(char *map_name)
{
	char	*extension;

	extension = ft_strchr(map_name, '.');
	if (!extension)
		return (1);
	else if (ft_strncmp(extension, ".ber", 4) != 0)
		return (1);
	return (0);
}

void	ft_parse_arguments(int argc, char *map_name)
{
	int	fd;

	fd = 2;
	if (argc < LIMIT_ARGS)
		ft_error("Please provide a map with extension .ber\n");
	else if (argc > LIMIT_ARGS)
		ft_error("Too many arguments!\n");
	else if (argc == LIMIT_ARGS && validate_extension(map_name))
		ft_error("Wrong file extension!\n");
}
