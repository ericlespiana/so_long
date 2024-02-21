/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:31:38 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/20 04:37:47 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_put_un_nbr(unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	if (nbr >= 10)
		count += ft_put_un_nbr(nbr / 10);
	count += ft_putchar((nbr % 10) + 48);
	return (count);
}

int	ft_putnumber(int nbr)
{
	int	count;
	int	sign;

	sign = 0;
	count = 0;
	if (nbr == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (nbr < 0)
	{
		sign = ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnumber((nbr / 10));
	count += ft_putchar((nbr % 10) + 48);
	return (count + sign);
}
