/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:19:27 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/03/21 03:00:00 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	// empty variables
	char	*ptr1; // strchr, strrchr
	char	*ptr2; // strchr, strrchr
	char	empty_1[20] = ""; // strcpy
	char	empty_2[20] = ""; // strcpy
	char	empty_3[20] = ""; // strncpy
	char	empty_4[20] = ""; // strncpy
	char	empty_7[20] = ""; // memcpy
	char	empty_8[20] = ""; // memcpy
	char	empty_9[20] = ""; // memccpy
	char	empty_10[20] = ""; // memccpy
	char	empty_11[20] = ""; // memmove
	char	empty_12[20] = ""; // memmove
	char	str_4[20] = ""; // bzero deplicate
	char	str_6[20] = ""; // memset deplicate
	char	concat_2[20] = ""; // strcat duplicate
	char	concat_4[20] = ""; // strncat duplicate

	// variables that receive values
	char	a = 'a'; // is and to, strchr, strrchr, memccpy
	char	b = 'r'; // strchr, strrchr, memchr
	char	c = 'e'; // memccpy
	char	d = '*'; // memset
	char	nbr[20] = "-1234"; //atoi
	char	str_1[20] = "Hello"; // strlen, strcpy, strncpy, strcat, strcmp, strncmp, strdup
	char	str_2[20] = "World!"; // strncat, strlcat, memcpy, memccpy
	char	str_3[20] = "Life"; // bzero
	char	str_5[20] = "Travel"; // memset
	char	concat_1[20] = "first "; // strcat
	char	concat_3[20] = "second "; // strncat
	char	concat_5[20] = "third "; // strlcat, strstr, strnstr, strchr, strrchr, memchr
	char	to_find[20] = "rd"; // strstr, strnstr

	// ranges
	int		n_cpy = 4; // strncpy nbr
	int		n_cmp = 4; // strncmp nbr
	int		n_cat = 4; // strncat nbr
	int		l_cat = 12; // strlcat nbr
	int		n_str = 6; // strnstr nbr
	int		m_cpy = 3; // memccpy nbr
	int		m_cmp = 5; // memcmp nbr
	int		m_move = 5; // memmove nbr
	int		n_bze = 2; // bzero nbr

	// only copies
	ft_strcpy(str_4, str_3); // bzero
	ft_strcpy(str_6, str_5); // memset
	ft_strcpy(concat_2, concat_1); // strcat
	ft_strcpy(concat_4, concat_3); // strncat
	char	*dup_or = strdup(str_1);
	char	*dup_ft = ft_strdup(str_1);

	// all functions and prints
	if (ft_isalpha(a))
	{
		// toupper
		printf("\n===== toupper =====\n\n");
		printf("Original: %c\n", ft_toupper(a));
		printf("Recreate: %c\n", toupper(a));

		// tolower
		printf("\n===== tolower =====\n\n");
		printf("Original: %c\n", tolower(a));
		printf("Recreate: %c\n", ft_tolower(a));
	}
	else
		printf("   Char [%c]\n", a);

	// isascii
	printf("\n===== isascii =====\n\n");
	printf("Original: %d\n", isascii(a));
	printf("Recreate: %d\n", ft_isascii(a));

	// isprint
	printf("\n===== isprint =====\n\n");
	printf("Original: %d\n", isprint(a));
	printf("Recreate: %d\n", ft_isprint(a));

	// isalnum
	printf("\n===== isalnum =====\n\n");
	printf("Original: %d\n", isalnum(a));
	printf("Recreate: %d\n", ft_isalnum(a));

	// isalpha
	printf("\n===== isalpha =====\n\n");
	printf("Original: %d\n", isalpha(a));
	printf("Recreate: %d\n", ft_isalpha(a));

	// isdigit
	printf("\n===== isdigit =====\n\n");
	printf("Original: %d\n", isdigit(a));
	printf("Recreate: %d\n", ft_isdigit(a));

	// atoi
	printf("\n===== atoi =====\n\n");
	printf("Original: %d\n", atoi(nbr));
	printf("Recreate: %d\n", ft_atoi(nbr));

	// strlen
	printf("\n===== strlen =====\n\n");
	printf("Original: %lu\n", strlen(str_1));
	printf("Recreate: %lu\n", ft_strlen(str_1));

	// strcpy
	printf("\n===== strcpy =====\n\n");
	printf("Original: %s\n", strcpy(empty_1, str_1));
	printf("Recreate: %s\n", ft_strcpy(empty_2, str_1));

	// strncpy
	printf("\n===== strncpy =====\n\n");
	printf("Original: %s\n", strncpy(empty_3, str_1, n_cpy));
	printf("Recreate: %s\n", ft_strncpy(empty_4, str_1, n_cpy));

	// strcat
	printf("\n===== strcat =====\n\n");
	printf("Original: %s\n", strcat(concat_1, str_1));
	printf("Recreate: %s\n", ft_strcat(concat_2, str_1));

	// strncat
	printf("\n===== strncat =====\n\n");
	printf("Original: %s\n", strncat(concat_3, str_2, n_cat));
	printf("Recreate: %s\n", ft_strncat(concat_4, str_2, n_cat));

	// strlcat
	printf("\n===== strlcat =====\n\n");
	printf("Recreate: %zu ", ft_strlcat(concat_5, str_2, l_cat));
	printf("[%s]\n", concat_5);

	// strcmp
	printf("\n===== strcmp =====\n\n");
	printf("Original: %d\n", strcmp(str_1, empty_3));
	printf("Recreate: %d\n", ft_strcmp(str_1, empty_3));

	// strncmp
	printf("\n===== strncmp =====\n\n");
	printf("Original: %d\n", strncmp(str_1, empty_3, n_cmp));
	printf("Recreate: %d\n", ft_strncmp(str_1, empty_3, n_cmp));

	// strdup
	printf("\n===== strdup =====\n\n");
	printf("Original: %s\n", dup_or);
	printf("Recreate: %s\n", dup_ft);
	
	// strstr
	printf("\n===== strstr =====\n\n");
	printf("Original: %s\n", strstr(concat_5, to_find));
	printf("Recreate: %s\n", ft_strstr(concat_5, to_find));

	// strnstr
	printf("\n===== strnstr =====\n\n");
	printf("Recreate: %s\n", ft_strnstr(concat_5, to_find, n_str));

	// strchr
	printf("\n===== strchr =====\n\n");
	ptr1 = strchr(concat_5, b);
	ptr2 = ft_strchr(concat_5, b);
	if (ptr1 != NULL)
		printf("Original: %c is found in [%s] at index %ld\n", *ptr1, concat_5, ptr1 - concat_5);
	if (ptr2 != NULL)
		printf("Recreate: %c is found in [%s] at index %ld\n", *ptr2, concat_5, ptr2 - concat_5);

	// strrchr
	printf("\n===== strrchr =====\n\n");
	ptr1 = strrchr(concat_5, b);
	ptr2 = ft_strrchr(concat_5, b);
	if (ptr1 != NULL)
		printf("Original: %c is last found in [%s] at index %ld\n", *ptr1, concat_5, ptr1 - concat_5);
	if (ptr2 != NULL)
		printf("Recreate: %c is last found in [%s] at index %ld\n", *ptr2, concat_5, ptr2 - concat_5);

	// memcpy
	printf("\n===== memcpy =====\n\n");
	memcpy(empty_7, str_2, (ft_strlen(str_2) + 1));
	printf("Original: %s\n", empty_7);
	
	ft_memcpy(empty_8, str_2, (ft_strlen(str_2) + 1));
	printf("Recreate: %s\n", empty_8);
	
	// memccpy
	printf("\n===== memccpy =====\n\n");
	memccpy(empty_9, str_2, c, m_cpy);
	printf("Original: %s\n", empty_9);

	ft_memccpy(empty_10, str_2, c, m_cpy);
	printf("Recreate: %s\n", empty_10);

	// memchr
	printf("\n===== memchr =====\n\n");
	ptr1 = memchr(concat_5, b, ft_strlen(concat_5));
	ptr2 = ft_memchr(concat_5, b, ft_strlen(concat_5));
	if (ptr1 != NULL)
		printf("Original: %c is found in [%s] at index %ld\n", *ptr1, concat_5, ptr1 - concat_5);
	if (ptr2 != NULL)
		printf("Recreate: %c is found in [%s] at index %ld\n", *ptr2, concat_5, ptr2 - concat_5);

	// memcmp
	printf("\n===== memcmp =====\n\n");
	printf("Original: %d\n", memcmp(str_1, empty_3, m_cmp));
	printf("Recreate: %d\n", ft_memcmp(str_1, empty_3, m_cmp));

	// memset
	printf("\n===== memset =====\n\n");
	printf("Original: %s ", str_5);
	memset(str_5, d, ft_strlen(str_5));
	printf("> %s\n", str_5);

	printf("Recreate: %s ", str_6);
	ft_memset(str_6, d, ft_strlen(str_6));
	printf("> %s\n", str_6);

	// memmove
	printf("\n===== memmove =====\n\n");
	memmove(empty_11, str_4, m_move);
	printf("Original: %s\n", empty_11);

	ft_memmove(empty_12, str_4, m_move);
	printf("Recreate: %s\n", empty_12);

	// bzero
	printf("\n===== bzero =====\n\n");
	int	b_size = ft_strlen(str_3);

	bzero(str_3, n_bze);
	printf("Original: ");
	for (int i = 0; i < b_size; i++)
        printf("[%d]", str_3[i]);

	ft_bzero(str_4, n_bze);
	printf("\nRecreate: ");
	for (int i = 0; i < b_size; i++)
        printf("[%d]", str_4[i]);
	printf("\n\n");
}
