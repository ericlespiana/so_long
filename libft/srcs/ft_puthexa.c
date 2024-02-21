/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:40:02 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/20 04:36:22 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_hexa(unsigned long long x, char *symbols)
{
	char	number[16];
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	if (x == 0)
		return (ft_putchar('0'));
	while (x > 0)
	{
		number[i] = symbols[x % 16];
		x /= 16;
		i++;
	}
	cont = i;
	number[i] = '\0';
	while (i--)
		ft_putchar(number[i]);
	return (cont);
}

int	ft_puthexa(unsigned long long hexa, int n)
{
	char	*symbols_lo;
	char	*symbols_up;
	int		total;

	symbols_lo = "0123456789abcdef";
	symbols_up = "0123456789ABCDEF";
	total = 0;
	if (n == 'x')
		total = convert_hexa(hexa, symbols_lo);
	else if (n == 'X')
		total = convert_hexa(hexa, symbols_up);
	else
	{
		if (hexa == 0)
			return (ft_putstr("(nil)"));
		else
		{
			total = ft_putstr("0x");
			total += convert_hexa(hexa, symbols_lo);
		}
	}
	return (total);
}
