/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:46:08 by erpiana           #+#    #+#             */
/*   Updated: 2023/10/29 07:46:11 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*temp;

	temp = NULL;
	if (lst && f)
	{
		temp = ft_lstnew(f(lst -> content));
		lst = lst -> next;
		while (lst)
		{
			ptr = ft_lstnew(f(lst -> content));
			if (!ptr)
			{
				ft_lstclear(&temp, del);
				return (NULL);
			}
			lst = lst -> next;
			ft_lstadd_back(&temp, ptr);
		}
	}
	return (temp);
}
