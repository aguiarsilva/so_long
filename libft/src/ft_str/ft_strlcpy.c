/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:33:36 by baguiar-          #+#    #+#             */
/*   Updated: 2024/07/05 11:53:17 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*source;
	size_t		destination_size;

	source = src;
	destination_size = dstsize;
	if (destination_size != 0)
	{
		while (--destination_size)
		{
			if (*source == '\0')
			{
				*dst++ = *source++;
				break ;
			}
			*dst++ = *source++;
		}
	}
	if (destination_size == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
		while (*source++)
			;
	}
	return (source - src - 1);
}
/*
size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	i = 0;
	if (n != 0)
	{
		while (src[i] != '\0' && (i < (n - 1)))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (lensrc);
} */
