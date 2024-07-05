/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:47:12 by baguiar-          #+#    #+#             */
/*   Updated: 2024/07/05 11:48:16 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"


char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	character;
	char	*return_value;

	ptr = (char *) s;
	character = (char) c;
	return_value = NULL;
	while (*ptr)
	{
		if (*ptr == character)
			return_value = ptr;
		ptr++;
	}
	if (*ptr == character)
		return (ptr);
	return (return_value);
}

/* char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}*/
