/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:21:53 by baguiar-          #+#    #+#             */
/*   Updated: 2024/07/05 11:52:30 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1) + 1;
	ptr = (char *) malloc(len);
	if (ptr != NULL)
		ft_strlcpy(ptr, s1, len);
	return (ptr);
}

/* char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
} */
