#ifndef BONUS_H
# define BONUS_H

#include "libft.h"

t_list	*ft_lst_toupper(t_list *elem);
void	ft_print_content(t_list *elem);
void	ft_print_list(t_list *list);
void	ft_free_content(void *content, size_t content_size);

t_list	*ft_lst_toupper(t_list *elem)
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

void	ft_print_content(t_list *elem)
{
	printf("  Content: %s\n", (char *)elem->content);
}

void	ft_free_content(void *content, size_t content_size)
{	
	(void)content_size;
	free(content);
}

void	ft_print_list(t_list *list)
{
	t_list *current = list;
	size_t	i = 1;
	size_t	len;

	printf("  List| Content       | Size  | Next Address\n");
	printf("  ----|---------------|-------|----------------\n");
	while (current != NULL)
	{
		printf("    %lu |", i);
		len = ft_strlen((char *)current->content);
		printf(" %s", (char *)current->content);
		if (len < 8)
			printf("\t      |");
		else if (len < 10)
			printf("     |");
		else
			printf("   |");
		if (len < 8)
			printf("   %lu   |", current->content_size);
		else
			printf("   %lu  |", current->content_size);
		printf(" %p\n", (void *)current->next);
		current = current->next;
		i++;
	}
}

#endif
