/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:19:27 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/03/23 02:39:45 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

int	main(void)
{
	char	*ptr1;
	char	*ptr2;
	char	emptyA[9][40] = {"", "", "", "", "", "", "", "", ""};
	char	emptyB[9][40] = {"", "", "", "", "", "", "", "", ""};
	char	commonChars[9] = {'a', '5', '@', ' ', 'j', '!', 'h', '*', '0'};
	char	upperChars[9] = {'R', 'O', 'B', 'O', 'T', 'I', 'C', 'S', 'W'};
	char	lowerChars[9] = {'a', 'i', 'm', 'l', 'e', 's', 's', 'y', 'z'};
	char	strs1[9][20] = {"int", "-42", "0", "42", "2147483648", "2147483647", "5678", "100000", "-100000"};
	char	strs2[9][20] ={"Programming ", "languages ", "like ", "Python ", "Java ", "and ", "C++ ", "are ", "used "};
	char	strs3[9][20] = {"robotics ", "is ", "the ", "future ", "of ", "technology ", "and ", "innovation ", "in "};
	char	strs4[9][20] =  {"mm", "an", "in", "on", "re", "in", " ", "0", "."};
	char	strs5[9][20] = {"fields", "like", "manufacturing", "medicine", "space", "exploration", "and", "more", "!"};
	char	strs6[9][20] = {"fields", "like", "manufacturing", "medicine", "space", "exploration", "and", "more", "!"};
	char	comb1[9][60] = {"I ", "am ", "happy ", "to ", "learn ", "new ", "things ", "and ", "grow "};
	char	comb2[9][60] = {"I ", "am ", "happy ", "to ", "learn ", "new ", "things ", "and ", "grow "};
	int		x;
	int		y;
	size_t	temp;

	// Prints auxiliar
	size_t		numberCases = 0;
	int		printAll = 0;
	int		newlinesBefore = 0;
	int		newlinesAfter = 3;
	char	startEndLine = '*';
	char	subjectsLine = '=';
	char	empty;

	// begin test
	insertHeadline("PART I", startEndLine, 1, 1);
	do
	{
        printf("Enter the number of cases (1-9): ");
        if (scanf("%lu", &numberCases) != 1) {
            scanf("%c", &empty);
            printf("Enter a number between 1 and 9.\n");
            numberCases = 0;
        }
    } while (numberCases < 1 || numberCases > 9);
	
	printf("Number of cases: %lu\n\n", numberCases);	

	PressKeyReadControl(&printAll);
	printf("\n");


	// toupper
	insertHeadline("toupper", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : %s%c%s\n", BLU, upperChars[i], STD);
		printf("  Original: %c\n", toupper(upperChars[i]));
		if (toupper(upperChars[i]) == ft_toupper(upperChars[i]))
			printf("%s  Remake  : %c\n%s", GRN, ft_toupper(upperChars[i]), STD);
		else
			printf("%s  Remake  : %c\n%s", RED, ft_toupper(upperChars[i]), STD);
		printf("\n\n\n");
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// tolower
	insertHeadline("tolower", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : %s%c%s\n", BLU, lowerChars[i], STD);
		printf("  Original: %c\n", tolower(lowerChars[i]));
		if (tolower(lowerChars[i]) == ft_tolower(lowerChars[i]))
			printf("%s  Remake  : %c\n%s", GRN, ft_tolower(lowerChars[i]), STD);
		else
			printf("%s  Remake  : %c\n%s", RED, ft_tolower(lowerChars[i]), STD);
		printf("\n\n\n");
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// isascii
	insertHeadline("isascii", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases - 1; i++)
	{
		printf("  Target  : %s%c%s is ascii?\n", BLU, commonChars[i], STD);
		printf("  Original: %s\n", isascii(commonChars[i]) ? "Yes" : "No");
		if (isascii(commonChars[i]) >= ft_isascii(commonChars[i]))
			printf("%s  Remake  : %s\n%s", GRN, ft_isascii(commonChars[i]) ? "Yes" : "No", STD);
		else
			printf("%s  Remake  : %s\n%s", RED, ft_isascii(commonChars[i]) ? "Yes" : "No", STD);
		printf("\n\n\n");
	}
	char	*nonAscii = "€";
	printf("  Target  : %s€%s is ascii?\n", BLU, STD);
	printf("  Original: %s\n", isascii(*nonAscii) ? "Yes" : "No");
	if (isascii(*nonAscii) >= ft_isascii(*nonAscii))
		printf("%s  Remake  : %s\n%s", GRN, ft_isascii(*nonAscii) ? "Yes" : "No", STD);
	else
		printf("%s  Remake  : %s\n%s", RED, ft_isascii(*nonAscii) ? "Yes" : "No", STD);
	printf("\n\n\n");

	if (!printAll)
		PressKeyReadControl(&printAll);
	// isprint
	insertHeadline("isprint", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases - 1; i++)
	{
		printf("  Target  : %s%c%s is printable?\n", BLU, commonChars[i], STD);
		printf("  Original: %s\n", isprint(commonChars[i]) ? "Yes" : "No");
		if (isprint(commonChars[i]) >= ft_isprint(commonChars[i]))
			printf("%s  Remake  : %s\n%s", GRN, ft_isprint(commonChars[i]) ? "Yes" : "No", STD);
		else
			printf("%s  Remake  : %s\n%s", RED, ft_isprint(commonChars[i]) ? "Yes" : "No", STD);
		printf("\n\n\n");
	}
	char	*nonPrint = "\n";
	printf("  Target  : %s\\n%s is printable?\n", BLU, STD);
	printf("  Original: %s\n", isprint(*nonPrint) ? "Yes" : "No");
	if (isprint(*nonPrint) >= ft_isprint(*nonPrint))
		printf("%s  Remake  : %s\n%s", GRN, ft_isprint(*nonPrint) ? "Yes" : "No", STD);
	else
		printf("%s  Remake  : %s\n%s", RED, ft_isprint(*nonPrint) ? "Yes" : "No", STD);
	printf("\n\n\n");

	if (!printAll)
		PressKeyReadControl(&printAll);
	// isalnum
	insertHeadline("isalnum", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : %s%c%s is alphanumeric?\n", BLU, commonChars[i], STD);
		printf("  Original: %s\n", isalnum(commonChars[i]) ? "Yes" : "No");
		if (isalnum(commonChars[i]) >= ft_isalnum(commonChars[i]))
			printf("%s  Remake  : %s\n%s", GRN, ft_isalnum(commonChars[i]) ? "Yes" : "No", STD);
		else
			printf("%s  Remake  : %s\n%s", RED, ft_isalnum(commonChars[i]) ? "Yes" : "No", STD);
		printf("\n\n\n");
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// isalpha
	insertHeadline("isalpha", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : %s%c%s is alphabetic?\n", BLU, commonChars[i], STD);
		printf("  Original: %s\n", isalpha(commonChars[i]) ? "Yes" : "No");
		if (isalpha(commonChars[i]) >= ft_isalpha(commonChars[i]))
			printf("%s  Remake  : %s\n%s", GRN, ft_isalpha(commonChars[i]) ? "Yes" : "No", STD);
		else
			printf("%s  Remake  : %s\n%s", RED, ft_isalpha(commonChars[i]) ? "Yes" : "No", STD);
		printf("\n\n\n");
	}
	
	if (!printAll)
		PressKeyReadControl(&printAll);
	// isdigit
	insertHeadline("isdigit", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : %s%c%s is digit?\n", BLU, commonChars[i], STD);
		printf("  Original: %s\n", isdigit(commonChars[i]) ? "Yes" : "No");
		if (isdigit(commonChars[i]) >= ft_isdigit(commonChars[i]))
			printf("%s  Remake  : %s\n%s", GRN, ft_isdigit(commonChars[i]) ? "Yes" : "No", STD);
		else
			printf("%s  Remake  : %s\n%s", RED, ft_isdigit(commonChars[i]) ? "Yes" : "No", STD);
		printf("\n\n\n");
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// atoi
	insertHeadline("atoi", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : %s%s%s\n", BLU, strs1[i], STD);
		printf("  Original: %d\n", atoi(strs1[i]));
		if (atoi(strs1[i]) == ft_atoi(strs1[i]))
			printf("%s  Remake  : %d\n%s", GRN, ft_atoi(strs1[i]), STD);
		else
			printf("%s  Remake  : %d\n%s", RED, ft_atoi(strs1[i]), STD);
		printf("\n\n\n");
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strlen
	insertHeadline("strlen", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : %s%s%s\n", BLU, strs2[i], STD);
		printf("  Original: %lu\n", strlen(strs2[i]));
		if (strlen(strs2[i]) == ft_strlen(strs2[i]))
			printf("%s  Remake  : %lu\n%s", GRN, ft_strlen(strs2[i]), STD);
		else
			printf("%s  Remake  : %lu\n%s", RED, ft_strlen(strs2[i]), STD);
		printf("\n\n\n");
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strcpy
	insertHeadline("strcpy", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Copy of %s%s%s\n", BLU, strs2[i], STD);
		strcpy(emptyA[i], strs2[i]);
		ft_strcpy(emptyB[i], strs2[i]);
		printf("  Original: %s\n", emptyA[i]);
		if (ft_strcmp(emptyA[i], emptyB[i]) == 0)
			printf("%s  Remake  : %s\n%s", GRN, emptyB[i], STD);
		else
			printf("%s  Remake  : %s\n%s", RED, emptyB[i], STD);
		printf("\n\n\n");
	}
	for (size_t i = 0; i < numberCases; i++)
	{
		ft_strclr(emptyA[i]);
		ft_strclr(emptyB[i]);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strncpy
	insertHeadline("strncpy", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Copy of %s%s%s until position %s%lu%s\n", BLU, strs2[i], STD, BLU, i + 1, STD);
		strncpy(emptyA[i], strs2[i], i + 1);
		ft_strncpy(emptyB[i], strs2[i], i + 1);
		printf("  Original: %s\n", emptyA[i]);
		if (ft_strcmp(emptyA[i], emptyB[i]) == 0)
			printf("%s  Remake  : %s\n%s", GRN, emptyB[i], STD);
		else
			printf("%s  Remake  : %s\n%s", RED, emptyB[i], STD);
		printf("\n\n\n");
	}
	for (size_t i = 0; i < numberCases; i++)
	{
		ft_strclr(emptyA[i]);
		ft_strclr(emptyB[i]);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strcat
	insertHeadline("strcat", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Concatenate %s%s%s with %s%s%s\n", BLU, comb1[i], STD, BLU, strs2[i], STD);
		strcat(comb1[i], strs2[i]);
		ft_strcat(comb2[i], strs2[i]);
		printf("  Original: %s\n", comb1[i]);
		if (ft_strcmp(comb1[i], comb2[i]) == 0)
			printf("%s  Remake  : %s\n%s", GRN, comb2[i], STD);
		else
			printf("%s  Remake  : %s\n%s", RED, comb2[i], STD);
		printf("\n\n\n");
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strncat
	insertHeadline("strncat", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Concatenate %s%s%s with %s%s%s until position %s%lu%s\n", \
		BLU, comb1[i], STD, BLU, strs3[i], STD, BLU, i + 1, STD);
		strncat(comb1[i], strs3[i], i + 1);
		ft_strncat(comb2[i], strs3[i], i + 1);
		printf("  Original: %s\n", comb1[i]);
		if (ft_strcmp(comb1[i], comb2[i]) == 0)
			printf("%s  Remake  : %s\n%s", GRN, comb2[i], STD);
		else
			printf("%s  Remake  : %s\n%s", RED, comb2[i], STD);
		printf("\n\n\n");
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strlcat
	insertHeadline("strlcat", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Buffer of Concatenate %s%s%s with %s%s%s\n", \
		BLU, comb1[i], STD, BLU, strs3[i], STD);
		temp = ft_strlcat(comb1[i], strs3[i], i + 20);
		printf("%s  Remake  : %lu [%s]\n%s", GRN, temp, comb1[i], STD);
		printf("\n\n\n");
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strcmp
	insertHeadline("strcmp", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Compare %s%s%s with %s%s%s\n", \
		BLU, strs2[i], STD, BLU, strs3[i], STD);
		x = strcmp(strs2[i], strs3[i]);
		y = ft_strcmp(strs2[i], strs3[i]);
		printf("  Original: %d\n", x);
		if (x == y)
			printf("%s  Remake  : %d\n%s", GRN, y, STD);
		else
			printf("%s  Remake  : %d\n%s", RED, y, STD);
		printf("\n\n\n");
		x = 0;
		y = 0;
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strncmp
	insertHeadline("strncmp", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Compare %s%s%s with %s%s%s until position %s%lu%s\n", \
		BLU, strs2[i], STD, BLU, strs3[i], STD, BLU, i, STD);
		x = strncmp(strs2[i], strs3[i], i);
		y = ft_strncmp(strs2[i], strs3[i], i);
		printf("  Original: %d\n", x);
		if (x == y)
			printf("%s  Remake  : %d\n%s", GRN, y, STD);
		else
			printf("%s  Remake  : %d\n%s", RED, y, STD);
		printf("\n\n\n");
		x = 0;
		y = 0;
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strdup
	insertHeadline("strdup", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Copy of %s%s%s\n", BLU, strs3[i], STD);
		ptr1 = strdup(strs3[i]);
		ptr2 = ft_strdup(strs3[i]);
		printf("  Original: %s\n", ptr1);
		if (ft_strcmp(ptr1, ptr2) == 0)
			printf("%s  Remake  : %s\n%s", GRN, ptr2, STD);
		else
			printf("%s  Remake  : %s\n%s", RED, ptr2, STD);
		printf("\n\n\n");
	}
	free(ptr1);
	free(ptr2);
	ptr1 = NULL;
	ptr2 = NULL;

	if (!printAll)
		PressKeyReadControl(&printAll);	
	// strstr
	insertHeadline("strstr", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Find %s%s%s in %s%s%s\n", BLU, strs4[i], STD, BLU, comb1[i], STD);
		ptr1 = strstr(comb1[i], strs4[i]);
		ptr2 = ft_strstr(comb1[i], strs4[i]);
		printf("  Original: %s\n", ptr1);
		if (ptr1 == NULL && ptr2 == NULL)
			printf("%s  Remake  : %s\n%s", GRN, ptr2, STD);
		else if (ft_strcmp(ptr1, ptr2) == 0)
			printf("%s  Remake  : %s\n%s", GRN, ptr2, STD);
		else
			printf("%s  Remake  : %s\n%s", RED, ptr2, STD);
		printf("\n\n\n");
		ptr1 = NULL;
		ptr2 = NULL;
	}
	free(ptr1);
	free(ptr2);

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strnstr
	insertHeadline("strnstr", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Find %s%s%s in %s%s%s until position %s%lu%s\n", \
		BLU, strs4[i], STD, BLU, comb1[i], STD, BLU, i + 8, STD);
		ptr2 = ft_strnstr(comb1[i], strs4[i], i + 8);
		printf("%s  Remake  : %s\n%s", GRN, ptr2, STD);
		printf("\n\n\n");
		ptr2 = NULL;
	}
	free(ptr2);

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strchr
	insertHeadline("strchr", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Find first %s%c%s in %s%s%s\n", BLU, commonChars[i], STD, BLU, comb1[i], STD);
		ptr1 = strchr(comb1[i], commonChars[i]);
		ptr2 = ft_strchr(comb1[i], commonChars[i]);
		if (ptr1 != NULL)
			printf("  Original: %c is found in [%s] at index %ld\n", *ptr1, comb1[i], ptr1 - comb1[i]);
		else
			printf("  Original: %s\n", ptr1);
		if (ptr2 != NULL)
		{
			if (ft_strcmp(ptr1, ptr2) == 0)
				printf("%s  Remake  : %c is found in [%s] at index %ld\n%s", GRN, *ptr2, comb1[i], ptr2 - comb1[i], STD);
			else
				printf("%s  Remake  : %c is found in [%s] at index %ld\n%s", RED, *ptr2, comb1[i], ptr2 - comb1[i], STD);
		}
		else
		{
			if (ptr1 == NULL && ptr2 == NULL)
				printf("%s  Remake  : %s\n%s", GRN, ptr2, STD);
			else
				printf("%s  Remake  : %s\n%s", RED, ptr2, STD);
		}
		printf("\n\n\n");
		ptr1 = NULL;
		ptr2 = NULL;
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// strrchr
	insertHeadline("strrchr", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Find last %s%c%s in %s%s%s\n", BLU, commonChars[i], STD, BLU, comb1[i], STD);
		ptr1 = strrchr(comb1[i], commonChars[i]);
		ptr2 = ft_strrchr(comb1[i], commonChars[i]);
		if (ptr1 != NULL)
			printf("  Original: %c is found in [%s] at index %ld\n", *ptr1, comb1[i], ptr1 - comb1[i]);
		else
			printf("  Original: %s\n", ptr1);
		if (ptr2 != NULL)
		{
			if (ft_strcmp(ptr1, ptr2) == 0)
				printf("%s  Remake  : %c is found in [%s] at index %ld\n%s", GRN, *ptr2, comb1[i], ptr2 - comb1[i], STD);
			else
				printf("%s  Remake  : %c is found in [%s] at index %ld\n%s", RED, *ptr2, comb1[i], ptr2 - comb1[i], STD);
		}
		else
		{
			if (ptr1 == NULL && ptr2 == NULL)
				printf("%s  Remake  : %s\n%s", GRN, ptr2, STD);
			else
				printf("%s  Remake  : %s\n%s", RED, ptr2, STD);
		}
		printf("\n\n\n");
		ptr1 = NULL;
		ptr2 = NULL;
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// memcpy
	insertHeadline("memcpy", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Copy of %s%s%s\n", BLU, strs2[i], STD);
		memcpy(emptyA[i], strs2[i], ft_strlen(strs2[i]) + 1);
		ft_memcpy(emptyB[i], strs2[i], ft_strlen(strs2[i]) + 1);
		printf("  Original: %s\n", emptyA[i]);
		if (ft_strcmp(emptyA[i], emptyB[i]) == 0)
			printf("%s  Remake  : %s\n%s", GRN, emptyB[i], STD);
		else
			printf("%s  Remake  : %s\n%s", RED, emptyB[i], STD);
		printf("\n\n\n");
	}
	for (size_t i = 0; i < numberCases; i++)
	{
		ft_strclr(emptyA[i]);
		ft_strclr(emptyB[i]);
	}
	
	if (!printAll)
		PressKeyReadControl(&printAll);
	// memccpy
	insertHeadline("memccpy", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Copy of %s%s%s\n", BLU, strs2[i], STD);
		memccpy(emptyA[i], strs2[i], commonChars[i], i + 1);
		ft_memccpy(emptyB[i], strs2[i], commonChars[i], i + 1);
		printf("  Original: %s\n", emptyA[i]);
		if (ft_strcmp(emptyA[i], emptyB[i]) == 0)
			printf("%s  Remake  : %s\n%s", GRN, emptyB[i], STD);
		else
			printf("%s  Remake  : %s\n%s", RED, emptyB[i], STD);
		printf("\n\n\n");
	}
	for (size_t i = 0; i < numberCases; i++)
	{
		ft_strclr(emptyA[i]);
		ft_strclr(emptyB[i]);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// memchr
	insertHeadline("memchr", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Find %s%c%s in %s%s%s\n", BLU, commonChars[i], STD, BLU, comb1[i], STD);
		ptr1 = memchr(comb1[i], commonChars[i], ft_strlen(comb1[i]));
		ptr2 = ft_memchr(comb1[i], commonChars[i], ft_strlen(comb1[i]));
		if (ptr1 != NULL)
			printf("  Original: %c is found in [%s] at index %ld\n", *ptr1, comb1[i], ptr1 - comb1[i]);
		else
			printf("  Original: %s\n", ptr1);
		if (ptr2 != NULL)
		{
			if (ft_strcmp(ptr1, ptr2) == 0)
				printf("%s  Remake  : %c is found in [%s] at index %ld\n%s", GRN, *ptr2, comb1[i], ptr2 - comb1[i], STD);
			else
				printf("%s  Remake  : %c is found in [%s] at index %ld\n%s", RED, *ptr2, comb1[i], ptr2 - comb1[i], STD);
		}
		else
		{
			if (ptr1 == NULL && ptr2 == NULL)
				printf("%s  Remake  : %s\n%s", GRN, ptr2, STD);
			else
				printf("%s  Remake  : %s\n%s", RED, ptr2, STD);
		}
		printf("\n\n\n");
		ptr1 = NULL;
		ptr2 = NULL;
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// memcmp
	insertHeadline("memcmp", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Compare %s%s%s with %s%s%s until position %s%lu%s\n", \
		BLU, strs2[i], STD, BLU, strs3[i], STD, BLU, i, STD);
		x = memcmp(strs2[i], strs3[i], i);
		y = ft_memcmp(strs2[i], strs3[i], i);
		printf("  Original: %d\n", x);
		if (x == y)
			printf("%s  Remake  : %d\n%s", GRN, y, STD);
		else
			printf("%s  Remake  : %d\n%s", RED, y, STD);
		printf("\n\n\n");
		x = 0;
		y = 0;
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// memset
	insertHeadline("memset", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : %s%s%s receive %s%c%s until position %s%lu%s\n", \
		BLU, strs5[i], STD, BLU, commonChars[i], STD, BLU, i + 1, STD);
		ft_strcpy(emptyA[i], strs5[i]);
		ft_strcpy(emptyB[i], strs6[i]);
		memset(strs5[i], commonChars[i], i + 1);
		ft_memset(strs6[i], commonChars[i], i + 1);
		printf("  Original: %s > %s\n", emptyA[i], strs5[i]);
		if (ft_strcmp(strs5[i], strs6[i]) == 0)
			printf("%s  Remake  : %s > %s\n%s", GRN, emptyB[i], strs6[i], STD);
		else
			printf("%s  Remake  : %s > %s\n%s", RED, emptyB[i], strs6[i], STD);
		printf("\n\n\n");
	}
	for (size_t i = 0; i < numberCases; i++)
	{
		ft_strclr(emptyA[i]);
		ft_strclr(emptyB[i]);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// memmove
	insertHeadline("memmove", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : Move %s%s%s to dest string until position %s%lu%s\n", \
		BLU, strs2[i], STD, BLU, i + 1, STD);
		memmove(emptyA[i], strs2[i], i + 1);
		ft_memmove(emptyB[i], strs2[i], i + 1);
		printf("  Original: %s\n", emptyA[i]);
		if (ft_strcmp(strs5[i], strs6[i]) == 0)
			printf("%s  Remake  : %s\n%s", GRN, emptyB[i], STD);
		else
			printf("%s  Remake  : %s\n%s", RED, emptyB[i], STD);
		printf("\n\n\n");
	}
	for (size_t i = 0; i < numberCases; i++)
	{
		ft_strclr(emptyA[i]);
		ft_strclr(emptyB[i]);
	}

	if (!printAll)
		PressKeyReadControl(&printAll);
	// bzero
	insertHeadline("bzero", subjectsLine, newlinesBefore, newlinesAfter);
	for (size_t i = 0; i < numberCases; i++)
	{
		printf("  Target  : %s%s%s receive 0 until position %s%lu%s\n", \
		BLU, strs2[i], STD, BLU, i + 1, STD);
		int	size = ft_strlen(strs2[i]);
		ft_strcpy(emptyA[i], strs2[i]);
		ft_strcpy(emptyB[i], strs2[i]);
		bzero(emptyA[i], i + 1);
		ft_bzero(emptyB[i], i + 1);
		printf("  Original: ");
		for (int j = 0; j < size; j++)
       		printf("[%c]", strs2[i][j]);
		printf(" > ");
		for (int j = 0; j < size; j++)
       		printf("[%c]", emptyA[i][j]);
		printf("\n");
		if (ft_strcmp(emptyA[i], emptyA[i]) == 0)
		{
			printf("%s  Remake  : ", GRN);
			for (int j = 0; j < size; j++)
				printf("[%c]", strs2[i][j]);
			printf(" > ");
			for (int j = 0; j < size; j++)
       			printf("[%c]", emptyB[i][j]);
			printf("\n%s", STD);
		}
		else
		{
			printf("%s  Remake  : ", RED);
			for (int j = 0; j < size; j++)
				printf("[%c]", strs2[i][j]);
			printf(" > ");
			for (int j = 0; j < size; j++)
       			printf("[%c]", emptyB[i][j]);
			printf("\n%s", STD);	
		}
		printf("\n\n\n");
	}
	insertHeadline("END", startEndLine, 0, 1);
}
