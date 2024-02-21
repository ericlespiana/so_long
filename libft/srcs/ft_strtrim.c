/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:53:24 by erpiana           #+#    #+#             */
/*   Updated: 2023/11/28 14:59:27 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size_cut;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_cut = ft_strlen(s1);
	while (*s1 && ft_strchr(set, s1[size_cut]))
		size_cut--;
	result = ft_substr(s1, 0, size_cut + 1);
	if (!result)
		return (NULL);
	return (result);
}
