/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:53:38 by erpiana           #+#    #+#             */
/*   Updated: 2023/11/27 23:47:03 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	length;
	size_t	j;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start >= length || len == 0)
		return (ft_strdup(""));
	if ((start + len) > length)
		len = length - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (s[start] != '\0' && j < len)
		ptr[j++] = s[start++];
	ptr[j] = '\0';
	return (ptr);
}
