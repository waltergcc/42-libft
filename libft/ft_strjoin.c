/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:15:03 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/03/19 01:36:57 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*concat;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	concat = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!concat)
		return (NULL);
	ft_memcpy(concat, s1, len1);
	ft_memcpy(concat + len1, s2, len2);
	concat[len1 + len2] = '\0';
	return (concat);
}
