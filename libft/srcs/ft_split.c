/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:36:13 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/19 05:42:00 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_size(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (*s == '\0')
		return (len);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			len++;
		i++;
	}
	return (len + 1);
}

static char	**allocate_substrings(char const *s, char **ptr, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			len++;
		if (s[i] == c || s[i + 1] == '\0')
		{
			ptr[j] = (char *)malloc(sizeof(char) * (len + 1));
			if (!ptr[j])
				return (NULL);
			j++;
			len = 0;
			while (s[i + 1] == c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}

static void	fill_matrix(char const *s, char **ptr, char c)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ptr[j][z] = s[i];
			z++;
		}
		if (s[i] == c || s[i + 1] == '\0')
		{
			ptr[j][z] = '\0';
			z = 0;
			j++;
			while (s[i + 1] == c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
}

static void	free_split(char *t, char c, char **ptr)
{
	int	i;

	i = 0;
	while (i < set_size(t, c))
	{
		free(ptr[i]);
		i++;
	}
	free(t);
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	set[2];
	char	*t;

	if (!s)
		return (NULL);
	set[0] = c;
	set[1] = '\0';
	t = ft_strtrim(s, set);
	if (!t)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (set_size(t, c) + 1));
	if (!ptr)
	{
		free(t);
		return (NULL);
	}
	if (!allocate_substrings(t, ptr, c))
	{
		free_split(t, c, ptr);
		return (NULL);
	}
	fill_matrix(t, ptr, c);
	free(t);
	return (ptr);
}
