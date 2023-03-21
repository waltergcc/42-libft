/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:19:27 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/03/21 02:19:03 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>

// used with ft_strmap
static char	ft_tolower_wrapper(char c) 
{
	int i = ft_tolower(c);
	return (i);
}

// used with ft_striter
static void	ft_toupper_wrapper(char *c) 
{
    *c = ft_toupper(*c);
}

// used with ft_strmapi
static char	ft_lowercase_plus_index(unsigned int i, char c)
{
	return (ft_tolower(c) + (i + 1));
}

// used with ft_striteri
static void	ft_replace_with_i(unsigned int i, char *c)
{
    *c = i + '0';
}

int	main(void)
{
	// file variable
	int	fd; // putchar_fd, putstr_fd, putendl_fd, ft_putnbr_fd
	char	buffer[1]; // putchar_fd, putstr_fd, putendl_fd, ft_putnbr_fd
	ssize_t bytes_read; // putchar_fd, putstr_fd, putendl_fd, ft_putnbr_fd
	
	// empty variables
	char	*empty; // itoa, memalloc, memdel, strdel, strmap, strmapi, strsub

	// variables that receive values
	int		n = -1234; // putnbr, itoa, ft_putnbr_fd
	char	a = 'a'; // putchar, putchar_fd
	char	b = '*'; // strsplit
	char	str_1[20] = "Hello"; // putstr, strjoin, striter, striteri
	char	str_2[20] = "World"; // strjoin, strequ, putendl, putstr_fd
	char	str_3[25] = "words*to**be****splitted"; // strsplit, strsub
	char	str_4[6] = "Hello"; // strclr
	char	str_5[6] = "WORLD"; // strclr, strmap, strmapi, strequ
	char	str_6[30] = " without.spaces  "; // strtrim, putendl_fd

	// ranges
	int	n_memalloc = 5; // memalloc
	int	n_strnew = 5; // strnew
	int	n_strclr = ft_strlen(str_4); // strclr
	int	n_strnequ = 1; // strnequ
	size_t	len_strsub = 2; // strsub
	unsigned int	start_strsub = 10; // strsub

	// putchar
	ft_putstr("\n===== putchar =====\n\n");
	ft_putchar(a);
	

	// putstr
	ft_putstr("\n\n===== putstr =====\n\n");
	ft_putstr(str_1);
	

	// putnbr
	ft_putstr("\n\n===== putnbr =====\n\n");
	ft_putnbr(n);
	

	// putendl
	ft_putstr("\n\n===== putendl =====\n\n");
	ft_putendl(str_2);

	// itoa
	ft_putstr("\n===== itoa =====\n\n");
	empty = ft_itoa(n);
	ft_putstr(empty);
	
	free(empty);

	// strjoin
	ft_putstr("\n\n===== strjoin =====\n\n");
	empty = ft_strjoin(str_1, str_2);
	ft_putstr(empty);
	free(empty);

	// strsplit
	char	**words = ft_strsplit(str_3, b);
	ft_putstr("\n\n===== strsplit =====\n\n");
	for (int i = 0; words[i] != NULL; i++)
	{
		ft_putstr("[");
		ft_putstr(words[i]);
		free(words[i]);
		ft_putstr("]");
	}
	free(words);

	// memalloc
	empty = ft_memalloc(n_memalloc);
	ft_putstr("\n\n===== memalloc =====\n\n");
	for (int i = 0; i < n_memalloc; i++)
	{
		ft_putstr("[");
        ft_putnbr(empty[i]);
		ft_putstr("]");
	}
	
	// memdel
	ft_putstr("\n\n===== memdel =====\n\n");
	printf("%p > ", (void*)empty);
	ft_memdel((void **) &empty);
	printf("%p\n", (void*)empty);

	// strnew
	empty = ft_strnew(n_strnew);
	ft_putstr("\n===== strnew =====\n\n");
	for (int i = 0; i < n_strnew; i++)
	{
		ft_putstr("[");
        ft_putnbr(empty[i]);
		ft_putstr("]");
	}
	
	// strdel
	ft_putstr("\n\n===== strdel =====\n\n");
	printf("%p > ", empty);
	ft_strdel(&empty);
	printf("%p\n", empty);

	// strclr
	ft_putstr("\n===== strclr =====\n\n");
	ft_putstr(str_4);
	ft_putstr(" > ");
	ft_strclr(str_4);
	for (int i = 0; i < n_strclr; i++)
	{
		ft_putstr("[");
        ft_putnbr(str_4[i]);
		ft_putstr("]");
	}

	// striter
	ft_putstr("\n\n===== striter =====\n\n");
	ft_striter(str_1, ft_toupper_wrapper);
	ft_putstr(str_1);

	// striteri
	ft_putstr("\n\n===== striteri =====\n\n");
	ft_putstr(str_1);
	ft_putstr(" > ");
	ft_striteri(str_1, ft_replace_with_i);
	ft_putstr(str_1);
	
	// strmap
	ft_putstr("\n\n===== strmap =====\n\n");
	ft_putstr(str_5);
	ft_putstr(" > ");
	empty = ft_strmap(str_5, ft_tolower_wrapper);
	ft_putstr(empty);
	free(empty);

	// strmapi
	ft_putstr("\n\n===== strmapi =====\n\n");
	ft_putstr(str_5);
	ft_putstr(" > ");
	empty = ft_strmapi(str_5, ft_lowercase_plus_index);
	ft_putstr(empty);
	free(empty);

	// strequ
	ft_putstr("\n\n===== strequ =====\n\n");
	if (ft_strequ(str_2, str_5))
		printf("%s is equal to %s\n", str_2, str_5);
	else
		printf("%s is not equal to %s\n", str_2, str_5);

	// strnequ
	ft_putstr("\n===== strnequ =====\n\n");
	if (ft_strnequ(str_2, str_5, n_strnequ))
		printf("%s is equal to %s at positon %d\n", str_2, str_5, n_strnequ);
	else
		printf("%s is not equal to %s at positon %d\n", str_2, str_5, n_strnequ);

	// strsub
	ft_putstr("\n===== strsub =====\n\n");
	ft_putstr(str_3);
	ft_putstr(" > ");
	empty = ft_strsub(str_3, start_strsub, len_strsub);
	ft_putstr(empty);
	free(empty);

	// strtrim
	ft_putstr("\n\n===== strtrim =====\n\n");
	ft_putstr("[");
	ft_putstr(str_6);
	ft_putstr("]");
	ft_putstr(" > ");
	empty = ft_strtrim(str_6);
	ft_putstr(empty);
	
	free(empty);

	// putchar_fd
	ft_putstr("\n\n===== putchar_fd =====\n\n");
    fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
	ft_putchar_fd(a, fd);
	close(fd);
	fd = open("output.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
	while ((bytes_read = read(fd, buffer, 1)) > 0)
		ft_putchar(*buffer);
	close(fd);
	

		// ft_putnbr_fd
	ft_putstr("\n\n===== ft_putnbr_fd =====\n\n");
    fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
	ft_putnbr_fd(n, fd);
	close(fd);
	fd = open("output.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
	while ((bytes_read = read(fd, buffer, 1)) > 0)
		ft_putchar(*buffer);
	close(fd);
	

	// putstr_fd
	ft_putstr("\n\n===== putstr_fd =====\n\n");
    fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
	ft_putstr_fd(str_2, fd);
	close(fd);
	fd = open("output.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
	while ((bytes_read = read(fd, buffer, 1)) > 0)
		ft_putchar(*buffer);
	close(fd);
	

	// putendl_fd
	ft_putstr("\n\n===== putendl_fd =====\n\n");
    fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
	ft_putendl_fd(str_6, fd);
	close(fd);
	fd = open("output.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
	while ((bytes_read = read(fd, buffer, 1)) > 0)
		ft_putchar(*buffer);
	close(fd);
	ft_putstr("\n");
}
