#ifndef TESTS_H
# define TESTS_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

# define MAX_WINDOW_WIDTH 80
# define STD "\033[0m"
# define RED "\033[31m"
# define GRN "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"

t_list	*ft_lst_toupper(t_list *elem);
size_t	getCaseNumbers();
int		getWidth();
char	ft_lowercase_plus_index(unsigned int i, char c);
void	PressKeyReadControl(int *printAll);
void 	insertHeadline(char *text, char c, int before, int after);
char	ft_tolower_wrapper(char c);
void	linesBetweenCases(size_t newLines);
void	ft_toupper_wrapper(char *c);
void	ft_replace_with_i(unsigned int i, char *c);
void	ft_print_content(t_list *elem);
void	ft_print_list(t_list *list);
void	ft_free_content(void *content, size_t content_size);

char	ft_tolower_wrapper(char c) 
{
	int i = ft_tolower(c);
	return (i);
}

void	ft_toupper_wrapper(char *c) 
{
    *c = ft_toupper(*c);
}

char	ft_lowercase_plus_index(unsigned int i, char c)
{
	return (ft_tolower(c) + (i + 1));
}

void	ft_replace_with_i(unsigned int i, char *c)
{
    *c = i + '0';
}

void	linesBetweenCases(size_t newLines)
{
	for (size_t i = 0; i < newLines; i++)
		printf("\n");
	printf("%s", STD);
}

void	PressKeyReadControl(int *printAll)
{
    printf("Press [Enter] to next, [a] to print all and [q] to exit.\n");
    while (1)
	{
        int c = getchar();

        if (c == '\n')
            break ;
        else if (c == 'q' || c == 'Q')
            exit(0);
		else if (c == 'a' || c == 'A')
			*printAll = 1;
    }
}

int getWidth()
{
    int width = MAX_WINDOW_WIDTH;

    #ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    #else
    struct winsize size;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) == 0)
	{
        width = size.ws_col;
    }
    #endif

    return (width);
}

void insertHeadline(char *text, char c, int before, int after)
{
    int window = getWidth();
    int textSize = strlen(text);
    int total = window - textSize - 4;
    int left = total / 2;
    int right = total - left;

    for (int i = 0; i < before; i++)
    	printf("\n");
    for (int i = 0; i < left; i++)
        printf("%c", c);
    printf("  %s  ", text);
    for (int i = 0; i < right; i++)
        printf("%c", c);
    for (int i = 0; i < after + 1; i++)
    	printf("\n");
}

size_t	getCaseNumbers(size_t startCase)
{
	char	empty; 
	size_t	numberCases = 0;
	do
	{
        printf("Enter the number of cases (%lu-9): ", startCase);
        if (scanf("%lu", &numberCases) != 1)
		{
            scanf("%c", &empty);
            printf("Enter a number between %lu and 9.\n", startCase);
            numberCases = 0;
        }
    } while (numberCases < startCase || numberCases > 9);
	printf("Number of cases: %lu\n\n", numberCases);	
	return (numberCases);
}

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
