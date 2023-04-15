/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:19:27 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/04/15 11:33:49 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include "bonus.h"

int	main(void)
{
	t_list	*list[9];
	t_list	*list2[9];
	t_list	*newList;
	t_list	*current;
	t_list	*previous = NULL;
	char	strs[9][20] ={"Programming", "languages", "like", "Python", "Java", "and", "C++", "are", "used"};

	// Prints auxiliar
	size_t	numberCases = 0;
	size_t	startCase = 2;
	int		printAll = 0;
	int		newlinesBefore = 0;
	int		newlinesAfter = 3;
	int		newlinesBetween = 3;
	char	subjectsLine = '=';
	char	startEndLine = '*';

	insertHeadline("BONUS", startEndLine, 1, 1);

	numberCases = getCaseNumbers(startCase);

	PressKeyReadControl(&printAll);
	printf("\n");

	// lstnew
	insertHeadline("lstnew", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		list[i] = ft_lstnew(strs[i]);
		printf("  Target: Create a list that get %s%s%s\n\n", BLU, strs[i], GRN);
		ft_print_list(list[i]);
		linesBetweenCases(newlinesBetween);
	}
	
	if (!printAll)
		PressKeyReadControl(&printAll);
	// lstadd_front
	insertHeadline("lstadd_front", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 1; i < numberCases; i++)
	{
		printf("  Target: Link list of %s%s%s with %s%s%s in the front%s\n\n", \
		BLU, (char*)list[i]->content, STD, BLU, (char*)list[0]->content, STD, GRN);
		ft_lstadd_front(&list[0], list[i]);
		ft_print_list(list[0]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// lstadd_back
	insertHeadline("lstadd_back", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
		list2[i] = ft_lstnew(strs[i]);
	for (size_t i = 1; i < numberCases; i++)
	{
		printf("  Target: Link list of %s%s%s with %s%s%s in the end%s\n\n", \
		BLU, (char*)list2[i]->content, STD, BLU, (char*)list2[0]->content, STD, GRN);
		ft_lstadd_back(&list2[0], list2[i]);
		ft_print_list(list2[0]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// lstiter
	insertHeadline("lstiter", subjectsLine, newlinesBefore, newlinesAfter);
	printf("  Target: Iterate the list with %sft_print_content%s\n\n", BLU, GRN);
	ft_lstiter(list[0], &ft_print_content);
	linesBetweenCases(newlinesBetween);

	if (!printAll)
		PressKeyReadControl(&printAll);
	// lstmap
	insertHeadline("lstmap", subjectsLine, newlinesBefore, newlinesAfter);
	printf("  Target: Create a new list iterating with %sft_lst_toupper%s\n\n", BLU, GRN);
	newList = ft_lstmap(list[0], &ft_lst_toupper, &ft_free_content);
	if (!newList)
		return (0);
	current = newList;
	while (current)
	{
		ft_print_content(current->content);
		current = current->next;
	}
	linesBetweenCases(newlinesBetween);

	if (!printAll)
		PressKeyReadControl(&printAll);
	// lstsize
	insertHeadline("lstsize", subjectsLine, newlinesBefore, newlinesAfter);
	printf("  Target: Size of list %s%s%s\n\n", BLU, (char*)newList->content, GRN);
	printf("    Size: %d", ft_lstsize(newList));
	linesBetweenCases(newlinesBetween);

	PressKeyReadControl(&printAll);
	// lstlast
	insertHeadline("lstlast", subjectsLine, newlinesBefore, newlinesAfter);
	printf("  Target: Return the last node of list %s%s%s\n\n", BLU, (char *)newList->content, GRN);
	ft_print_list(ft_lstlast(newList));
	linesBetweenCases(newlinesBetween);
	
	if (!printAll)
		PressKeyReadControl(&printAll);
	// lstdelone
	insertHeadline("lstdelone", subjectsLine, newlinesBefore, newlinesAfter);
	printf("  Target: Delete the node of postion %s%lu%s\n", BLU, numberCases, STD);
	printf("\n  List before:\n\n");
	ft_print_list(newList);
	if (newList)
	{
		current = newList;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		if (previous != NULL)
			previous->next = NULL;
		ft_lstdelone(current, &ft_free_content);
	}
	printf("\n%s  List after:\n\n", GRN);
	ft_print_list(newList);
	linesBetweenCases(newlinesBetween);

	if (!printAll)
		PressKeyReadControl(&printAll);
	// lstclear
	insertHeadline("lstclear", subjectsLine, newlinesBefore, newlinesAfter);
	printf("  Target: Delete all linked list\n");
	printf("\n  List before:\n\n");
	ft_print_list(newList);
	ft_lstclear(&newList, &ft_free_content);
	printf("\n%s  List after: ", GRN);
	printf("%p\n", (void *)newList);
	linesBetweenCases(newlinesBetween);

	insertHeadline("END", startEndLine, 0, 1);
}
