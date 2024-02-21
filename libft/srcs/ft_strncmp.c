/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:52:34 by erpiana           #+#    #+#             */
/*   Updated: 2023/10/29 07:52:36 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (*ptr_s1 != '\0' || *ptr_s2 != '\0'))
	{
		if (*ptr_s1 != *ptr_s2)
			return ((int)*ptr_s1 - (int)*ptr_s2);
		ptr_s1++;
		ptr_s2++;
		i++;
	}
	return (0);
}
