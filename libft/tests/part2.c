/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:19:27 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/03/24 00:12:52 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

int	main(void)
{
	// file variable
	int		fd;
	char	buffer[1];
	ssize_t bytes_read;

	char	*empty[9];
	char	spaceChar = ' ';
	char	commonChars[9] = {'a', '5', '@', ' ', 'j', '!', 'h', '*', '0'};
	char	strs1[9][20] ={"Programming ", "languages ", "like ", "Python ", "Java ", "and ", "C++ ", "are ", "used "};
	char	strs2[9][20] = {"robotics ", "is ", "the ", "future ", "of ", "technology ", "and ", "innovation ", "in "};
	char	strs3[9][20] = {"fIeLdS", "LIKE", "MANUfactURING", "mediciNE", "sPACe", "ExPlOrAtIoN", "AND", "mOre", "!"};
	char	strs4[9][20] =  {" 	mm", "an 		", " in ", "	on	", "re st", " in", " ", " 0  ", " . "};
	char	cleaned[9][60] = {"I ", "am ", "happy ", "to ", "learn ", "new ", "things ", "and ", "grow "};
	char	frases[9][40] = {"The quick brown fox", "A lazy dog", "Star Wars", "Science Fiction movie", "Rock Music", "Artificial Intelligence is cool", "Hey Bro", "It's a nice day", "You're welcome"}; 
	int		nbrs[9] = {1, -42, 0, 42, 2147483648, 2147483647, 5678, 100000, -100000};
	
	// Prints auxiliar
	size_t	numberCases = 0;
	size_t	startCase = 1;
	int		printAll = 0;
	int		newlinesBefore = 0;
	int		newlinesAfter = 3;
	int		newlinesBetween = 4;
	char	subjectsLine = '=';
	char	startEndLine = '*';

	// begin test
	remove("output.txt");
	insertHeadline("PART II", startEndLine, 1, 1);

	numberCases = getCaseNumbers(startCase);

	PressKeyReadControl(&printAll);
	printf("\n");

	// putchar
	insertHeadline("putchar", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Print %s%c%s\n", BLU, commonChars[i], GRN);
		ft_putstr("  Remake: ");
		ft_putchar(commonChars[i]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// putstr
	insertHeadline("putstr", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Print %s%s%s\n", BLU, strs1[i], GRN);
		ft_putstr("  Remake: ");
		ft_putstr(strs1[i]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// putnbr
	insertHeadline("putnbr", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Print %s%d%s\n", BLU, nbrs[i], GRN);
		ft_putstr("  Remake: ");
		ft_putnbr(nbrs[i]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);	
	// putendl
	insertHeadline("putendl", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Print %s%s%s with a new line%s\n", BLU, strs1[i], STD, GRN);
		ft_putstr("  Remake: ");
		ft_putendl(strs1[i]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// itoa
	insertHeadline("itoa", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Store %s%d%s in an array%s\n", BLU, nbrs[i], STD, GRN);
		empty[i] = ft_itoa(nbrs[i]);
		ft_putstr("  Remake: ");
		ft_putstr(empty[i]);
		linesBetweenCases(newlinesBetween);
	}
	for (size_t i = 0; i < numberCases; i++)
		free(empty[i]);

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strjoin
	insertHeadline("strjoin", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Combine %s%s%s with %s%s%s\n", BLU, strs1[i], STD, BLU, strs2[i], GRN);
		empty[i] = ft_strjoin(strs1[i], strs2[i]);
		ft_putstr("  Remake: ");
		ft_putstr(empty[i]);
		linesBetweenCases(newlinesBetween);
	}
	for (size_t i = 0; i < numberCases; i++)
		free(empty[i]);

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strsplit
	insertHeadline("strsplit", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		char	**words = ft_strsplit(frases[i], spaceChar);
		printf("  Target: Split %s%s%s with '%c'%s\n", BLU, frases[i], STD, spaceChar, GRN);
		ft_putstr("  Remake: ");
		for (size_t j = 0; words[j] != NULL; j++)
		{
			printf("[%s]", words[j]);
			free(words[j]);
		}
		free(words);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// memalloc
	insertHeadline("memalloc", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Alloc memory of size %s%lu%s\n", BLU, i + 1, GRN);
		empty[i] = ft_memalloc(i + 1);
		ft_putstr("  Remake: ");
		for (size_t j = 0; j < i + 1; j++)
			printf("[%s]", empty[j]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// memdel
	insertHeadline("memdel", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Erase memory in %s%p%s\n", BLU, (void*)empty[i], GRN);
		printf("  Remake: %p > ", (void*)empty[i]);
		ft_memdel((void **) &empty[i]);
		printf("%p", (void*)empty[i]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strnew
	insertHeadline("strnew", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Create a str of size %s%lu%s\n", BLU, i + 1, GRN);
		empty[i] = ft_strnew(i + 1);
		ft_putstr("  Remake: ");
		for (size_t j = 0; j < i + 1; j++)
			printf("[%s]", empty[j]);
		linesBetweenCases(newlinesBetween);
	}
	
	if (!printAll)
		PressKeyReadControl(&printAll);
	// strdel
	insertHeadline("strdel", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Erase string in %s%p%s\n", BLU, (void*)empty[i], GRN);
		printf("  Remake: %p > ", empty[i]);
		ft_strdel(&empty[i]);
		printf("%p", empty[i]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strclr
	insertHeadline("strclr", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		size_t	len = ft_strlen(cleaned[i]);
		printf("  Target: Clear the string '%s%s%s'%s\n", BLU, cleaned[i], STD, GRN);
		ft_strclr(cleaned[i]);
		ft_putstr("  Remake: ");
		for (size_t j = 0; j < len; j++)
			printf("[%d]", cleaned[i][j]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// striter
	insertHeadline("striter", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Iterate with %sft_toupper_wrapper%s\n", BLU, GRN);
		printf("  Remake: %s > ", strs1[i]);
		ft_striter(strs1[i], ft_toupper_wrapper);
		printf("%s", strs1[i]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// striteri
	insertHeadline("striteri", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Iterate with %sft_replace_with_i%s\n", BLU, GRN);
		printf("  Remake: %s > ", strs1[i]);
		ft_striteri(strs1[i], ft_replace_with_i);
		printf("%s", strs1[i]);
		linesBetweenCases(newlinesBetween);
	}
	
	if (!printAll)
		PressKeyReadControl(&printAll);
	// strmap
	insertHeadline("strmap", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Create new string iterating with %sft_tolower_wrapper%s\n", BLU, GRN);
		printf("  Remake: %s > ", strs3[i]);
		empty[i] = ft_strmap(strs3[i], ft_tolower_wrapper);
		printf("%s", empty[i]);
		free(empty[i]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strmapi
	insertHeadline("strmapi", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Create new string iterating with %sft_lowercase_plus_index%s\n", BLU, GRN);
		printf("  Remake: %s > ", strs3[i]);
		empty[i] = ft_strmapi(strs3[i], ft_lowercase_plus_index);
		printf("%s", empty[i]);
		free(empty[i]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strequ
	insertHeadline("strequ", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Check if %s%s%s is equal to %s%s%s\n", BLU, strs2[i], STD, BLU, strs3[i], GRN);
		if (ft_strequ(strs2[i], strs3[i]))
			printf("  Remake: They are equals");
		else
			printf("  Remake: They aren't equals");
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strnequ
	insertHeadline("strnequ", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Check if %s%s%s is equal to %s%s%s until position %s%lu%s\n", \
		BLU, strs2[i], STD, BLU, strs3[i], STD, BLU, i, GRN);
		if (ft_strnequ(strs2[i], strs3[i], i))
			printf("  Remake: They are equals");
		else
			printf("  Remake: They aren't equals");
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strsub
	insertHeadline("strsub", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Get a substring of %s%s%s\n", BLU, frases[i], GRN);
		printf("  Remake: %s > ", frases[i]);
		empty[i] = ft_strsub(frases[i], i, i * i);
		printf("%s", empty[i]);
		free(empty[i]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strtrim
	insertHeadline("strtrim", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Remove spaces of [%s%s%s] from start and end%s\n", BLU, strs4[i], STD, GRN);
		printf("  Remake: %s > ", strs4[i]);
		empty[i] = ft_strtrim(strs4[i]);
		printf("%s", empty[i]);
		free(empty[i]);
		linesBetweenCases(newlinesBetween);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// putchar_fd
	insertHeadline("putchar_fd", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Write %s%c%s in a file%s\n", BLU, commonChars[i], STD, GRN);
		fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
		if (fd == -1)
		{
			perror("open");
			return (1);
		}
		ft_putchar_fd(commonChars[i], fd);
		close(fd);
		fd = open("output.txt", O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			return (1);
		}
		printf("  Remake: output.txt > ");
		while ((bytes_read = read(fd, buffer, 1)) > 0)
			printf("%c", *buffer);
		close(fd);
		remove("output.txt");
		linesBetweenCases(newlinesBetween);
	}
	remove("output.txt");

	if (!printAll)
		PressKeyReadControl(&printAll);
	// ft_putnbr_fd
	insertHeadline("ft_putnbr_fd", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Write %s%d%s in a file%s\n", BLU, nbrs[i], STD, GRN);
		fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
		if (fd == -1)
		{
			perror("open");
			return (1);
		}
		ft_putnbr_fd(nbrs[i], fd);
		close(fd);
		fd = open("output.txt", O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			return (1);
		}
		printf("  Remake: output.txt > ");
		while ((bytes_read = read(fd, buffer, 1)) > 0)
			printf("%c", *buffer);
		close(fd);
		remove("output.txt");
		linesBetweenCases(newlinesBetween);
	}
	remove("output.txt");

	if (!printAll)
		PressKeyReadControl(&printAll);
	// putstr_fd
	insertHeadline("putstr_fd", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Write %s%s%s in a file%s\n", BLU, frases[i], STD, GRN);
		fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
		if (fd == -1)
		{
			perror("open");
			return (1);
		}
		ft_putstr_fd(frases[i], fd);
		close(fd);
		fd = open("output.txt", O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			return (1);
		}
		printf("  Remake: output.txt > ");
		while ((bytes_read = read(fd, buffer, 1)) > 0)
			printf("%c", *buffer);
		close(fd);
		remove("output.txt");
		linesBetweenCases(newlinesBetween);
	}
	remove("output.txt");

	if (!printAll)
		PressKeyReadControl(&printAll);
	// putendl_fd
	insertHeadline("putendl_fd", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target: Write %s%s%s in a file with a new line%s\n", BLU, frases[i], STD, GRN);
		fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
		if (fd == -1)
		{
			perror("open");
			return (1);
		}
		ft_putendl_fd(strs2[i], fd);
		close(fd);
		fd = open("output.txt", O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			return (1);
		}
		printf("  Remake: output.txt > ");
		while ((bytes_read = read(fd, buffer, 1)) > 0)
			printf("%c", *buffer);
		close(fd);
		remove("output.txt");
		linesBetweenCases(newlinesBetween);
	}
	remove("output.txt");

	insertHeadline("END", startEndLine, 0, 1);
}
