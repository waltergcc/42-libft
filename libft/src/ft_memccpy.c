/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:07:24 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/03/18 18:47:43 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	while (n > 0)
	{
		*pdest = *psrc;
		if (*psrc == (unsigned char)c)
			return ((void *)pdest);
		pdest++;
		psrc++;
		n--;
	}
	return (NULL);
}
