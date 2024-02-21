/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:46:59 by erpiana           #+#    #+#             */
/*   Updated: 2023/10/29 07:47:01 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		chr;

	chr = (unsigned char)c;
	str = (const unsigned char *)s;
	while (n > 0)
	{
		if (chr == *str)
			return ((void *)str);
		n--;
		str++;
	}
	return (NULL);
}
