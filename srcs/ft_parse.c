/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:01:55 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/27 08:27:34 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include "ft_utils_error.h"

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
		ft_error("Error!\nPlease provide a map with extension .ber\n");
	else if (argc > LIMIT_ARGS)
		ft_error("Error!\nToo many arguments!\n");
	else if (argc == LIMIT_ARGS && validate_extension(map_name))
		ft_error("Error\nWrong file extension!\n");
}
