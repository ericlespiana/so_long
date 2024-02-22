/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:01:55 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/22 19:50:41 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static int	validate_extension(char *map_name);

void	ft_parse_arguments(int argc, char *map_name)
{
	int	fd;

	fd = 2;
	if (argc < LIMIT_ARGS)
		ft_putstr_fd("Error!\nPlease provide a map with extension .ber\n", fd);
	else if (argc > LIMIT_ARGS)
		ft_putstr_fd("Error!\nToo many arguments!", fd);
	else if (argc == LIMIT_ARGS && validate_extension(map_name))
		ft_putstr_fd("Error\nWrong file extension!", fd);
	else
		return ;
	exit(EXIT_FAILURE);
}

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
