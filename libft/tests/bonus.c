/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:19:27 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/03/21 01:26:28 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>

static t_list	*ft_lst_toupper(t_list *elem)
{
	char	*new_str;
	t_list	*node;
	size_t	i = 0;

	new_str = ft_strdup(elem->content);
	if (!new_str)
		return (NULL);
	while (new_str[i])
	{
    	new_str[i] = ft_toupper(new_str[i]);
    	i++;
	}
	node = ft_lstnew(new_str, ft_strlen(new_str) + 1);
	if (!node)
	{
		free(new_str);
		return (NULL);
	}
	return (node);
}

static void	ft_print_content(t_list *elem)
{
	printf("%s\n", (char *)elem->content);
}

static void	ft_free_content(void *content, size_t content_size)
{	
	(void)content_size;
	free(content);
}

static void	ft_print_list(t_list *list)
{
	t_list *current = list;
	size_t	i = 1;

	while (current != NULL)
	{
		printf("List %lu: ", i);
		printf("content = [%s] ", (char *)current->content);
		printf("size = %lu ", current->content_size);
		printf("next = %p\n", (void *)current->next);
		current = current->next;
		i++;
	}
}

int	main(void)
{
	// creation of the list;
	t_list	*list_1; // lstnew, ltsadd, lstdelone
	t_list	*list_2; // ltsadd
	t_list	*list_3; // ltsadd
	t_list	*list_4; // lstmap
	t_list	*modified; //lstmap
	t_list	*temp; //lstmap


	// variables that receive values
	char	str_1[20] = "hello"; // lstnew, ltsadd
	char	str_2[20] = "world"; // ltsadd
	char	str_3[20] = "today"; // ltsadd
	char	str_4[20] = "forever"; // lstmap

	// lstnew
	ft_putstr("\n===== lstnew =====\n\n");
	list_1 = ft_lstnew(str_1, ft_strlen(str_1) + 1);
	ft_print_list(list_1);
	
	// lstadd
	ft_putstr("\n===== lstadd =====\n\n");
	list_2 = ft_lstnew(str_2, ft_strlen(str_2) + 1);
	list_3 = ft_lstnew(str_3, ft_strlen(str_3) + 1);
	ft_lstadd(&list_1, list_2);
	ft_lstadd(&list_1, list_3);
	ft_print_list(list_1);

	// lstiter
	ft_putstr("\n===== lstiter =====\n\n");
	ft_lstiter(list_1, &ft_print_content);

	// lstmap
	ft_putstr("\n===== lstmap =====\n\n");
	list_4 = ft_lstnew(str_4, ft_strlen(str_4) + 1);
	ft_lstadd(&list_1, list_4);
	modified = ft_lstmap(list_1, &ft_lst_toupper);
	if (!modified)
	{
		printf("Error: Failed to create new list.\n");
		return (1);
	}
	temp = modified;
	while (temp)
	{
		ft_print_content(temp);
		temp = temp->next;
	}
	ft_lstdel(&list_1, &ft_free_content);

	// lstdelone
	ft_putstr("\n===== lstdelone =====\n\n");
	printf("Before:\n\n");
	ft_print_list(modified);
	ft_lstdelone(&modified->next->next->next, &ft_free_content);
	printf("\nAfter:\n\n");
	ft_print_list(modified);

	// lstdel
	ft_putstr("\n===== lstdel =====\n\n");
	printf("Before:\n\n");
	ft_print_list(modified);
	ft_lstdel(&modified, &ft_free_content);
	printf("\nAfter: ");
	printf("%p\n", (void *)modified);
	printf("\n");
}
