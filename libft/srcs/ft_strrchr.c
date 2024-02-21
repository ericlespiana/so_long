/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:53:08 by erpiana           #+#    #+#             */
/*   Updated: 2023/11/27 23:47:26 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	find_c;

	find_c = c;
	len = ft_strlen(s);
	if (c == 0)
		return ((char *)s + len);
	while (s[len] != find_c && len != 0)
		len--;
	if (s[len] == find_c)
		return ((char *)s + len);
	return (NULL);
}
