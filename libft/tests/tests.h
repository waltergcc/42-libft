#ifndef TESTS_H
# define TESTS_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

# define MAX_WINDOW_WIDTH 80
# define BLU "\033[34m"
# define GRN "\033[32m"
# define RED "\033[31m"
# define STD "\033[0m"

void	PressKeyReadControl(int *printAll);
int		getWidth();
void 	insertHeadline(char *text, char c, int before, int after);

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

#endif
