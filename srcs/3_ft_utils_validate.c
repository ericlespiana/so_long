/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ft_utils_validate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:51:30 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 07:39:46 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_validate.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	failt_temp(int fd)
{
	close(fd);
	ft_error("Error\nThis file is empty!\n");
}

int	open_file(char *file)
{
	int	fd;
	
	fd = open(file, O_RDONLY, 0666);
	if (fd == -1)
		ft_error("Error to open map!\n");
	return (fd);
}
