/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 02:50:31 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/29 11:57:25 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	main(int argc, char *argv[])
{
	ft_parse_arguments(argc, argv[1]);
	ft_validate(argv[1]);
	return (EXIT_SUCCESS);
}
