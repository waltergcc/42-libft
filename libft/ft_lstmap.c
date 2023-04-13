/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:08:17 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/03/21 00:04:27 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*current;

	new_lst = NULL;
	current = NULL;
	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (!new_lst)
		return (NULL);
	current = new_lst;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!current->next)
			return (NULL);
		current = current->next;
		lst = lst->next;
	}
	return (new_lst);
}
