/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 02:50:37 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 07:01:45 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "ft_utils_validate.h"
# include "libft.h"
# include <fcntl.h>

void	ft_parse_arguments(int argc, char *map_name);
void	ft_validate(char *map_name);

# define LIMIT_ARGS 2
# define TRUE 1
# define FALSE 0

typedef struct maps
{
	int	fd;
	int	start;
	int	exit;
	int	collectibles;
}	t_map;

#endif
