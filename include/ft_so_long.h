/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 02:50:37 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 10:02:17 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "libft.h"
# include <fcntl.h>

typedef struct s_maps
{
	int	fd;
	int	start;
	int	exit;
	int	collectibles;
}	t_map;

void		ft_parse_arguments(int argc, char *map_name);
void		ft_validate(char *map_name);
void		init_variable_map(t_map *map);
void		ft_error(char *msg);
void		fail_temp(int fd);
int			open_file(char *file);
int			check_proportion(char *tmp, size_t c_size);
int			check_walls(char *tmp, size_t c_size, int time);

# define LIMIT_ARGS 2
# define TRUE 1
# define FALSE 0

#endif
