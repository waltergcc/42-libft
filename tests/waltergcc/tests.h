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

void	ft_strclr(char *s);
char	*ft_strcpy(char *dest, const char *src);
void	*ft_memalloc(size_t size);
void	ft_putstr(char const *s);
int		ft_strcmp(const char *s1, const char *s2);
size_t	getCaseNumbers();
int		getWidth();
char	ft_lowercase_plus_index(unsigned int i, char c);
void	PressKeyReadControl(int *printAll);
void 	insertHeadline(char *text, char c, int before, int after);
char	ft_tolower_wrapper(char c);
void	linesBetweenCases(size_t newLines);
void	ft_toupper_wrapper(char *c);
void	ft_replace_with_i(unsigned int i, char *c);

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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_strclr(char *s)
{
	if (!s)
		return ;
	while (*s)
		*s++ = '\0';
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

void	ft_putstr(char const *s)
{
	while (*s)
		write(1, s++, 1);
}

#endif
