#ifndef BONUS_H
# define BONUS_H

#include "libft.h"

void	*ft_lst_toupper(void *elem);
void	ft_print_content(void *elem);
void	ft_print_list(t_list *list);
void	ft_free_content(void *content);


void	*ft_lst_toupper(void *elem)
{
	char	*new_str;
	size_t	i = 0;

	new_str = ft_strdup((char *)elem);
	if (!new_str)
		return (NULL);
	while (new_str[i])
	{
		new_str[i] = ft_toupper(new_str[i]);
		i++;
	}
	new_str[i] = '\0';
	return ((void *)new_str);
}

void	ft_print_content(void *elem)
{
	printf("  Content: %s\n", (char *)elem);
}

void	ft_free_content(void *content)
{	
	free(content);
}

void	ft_print_list(t_list *list)
{
	t_list *current = list;
	size_t	i = 1;
	size_t	len;

	printf("  List| Content       | Next Address\n");
	printf("  ----|---------------|----------------\n");
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
		printf(" %p\n", (void *)current->next);
		current = current->next;
		i++;
	}
}

#endif
