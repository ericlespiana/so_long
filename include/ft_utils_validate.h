/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_validate.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:51:11 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 07:40:03 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_VALIDATE_H
# define FT_UTILS_VALIDATE_H

# include "ft_so_long.h"

void	ft_error(char *msg);
void	failt_temp(int fd);
int		open_file(char *file);

#endif