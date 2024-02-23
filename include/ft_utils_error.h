/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_error.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:51:11 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/23 08:53:45 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_ERROR_H
# define FT_UTILS_ERROR_H

# define READ_ERROR "Error\nIt was no possible to read the file descriptor\n"
# define JOIN_ERROR "Error\nCan't join strings\n"
# define ERROR_COLUMN "Error\nColumn don't have the same proportion\n"
# define ERROR_WALL "Error\nMap don't surrounded by 1\n"

void	ft_error(char *msg);

#endif