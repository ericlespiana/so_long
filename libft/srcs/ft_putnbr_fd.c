/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:49:03 by erpiana           #+#    #+#             */
/*   Updated: 2023/10/29 07:49:05 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	buffer[11];

	i = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	while (n > 0)
	{
		buffer[i] = (n % 10) + 48;
		i++;
		n /= 10;
	}
	buffer[i] = '\0';
	while (--i >= 0)
		ft_putchar_fd(buffer[i], fd);
}
