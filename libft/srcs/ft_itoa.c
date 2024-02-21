/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:44:12 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/16 16:36:01 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	counter_elements(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	to_char(int n)
{
	return (n + '0');
}

int	check_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	int		is_negative;
	int		tot_elements;
	char	*ptr;

	is_negative = check_negative(n);
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (is_negative)
		n = -n;
	tot_elements = counter_elements(n) + is_negative;
	ptr = (char *)malloc(sizeof(char) * (tot_elements + 1));
	if (!ptr)
		return (NULL);
	if (is_negative)
		ptr[0] = '-';
	ptr[tot_elements] = '\0';
	while (tot_elements-- > is_negative)
	{
		ptr[tot_elements] = to_char((n % 10));
		n /= 10;
	}
	return (ptr);
}
