/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:33:57 by erpiana           #+#    #+#             */
/*   Updated: 2024/03/26 11:33:28 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	main(int argc, char *argv[])
{
	ft_parse_arguments(argc, argv[1]);
	ft_validate(argv[1]);
	return (EXIT_SUCCESS);
}
