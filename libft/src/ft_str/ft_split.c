/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:14:12 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/21 22:14:12 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static size_t	ft_strcspn(const char *s, char c)
{
	size_t	span;

	span = 0;
	while (*s && (*s != c))
	{
		s++;
		span++;
	}
	return (span);
}

/*
** NAME
** 		ft_strspn -- spans a string
** DESCRIPTION
** 		The ft_strspnstrspn() function spans the initial part of the null-
** 		terminated string s as long as the character c occur.  In other words,
** 		it computes the string array index of the first character of s
** 		which is other than c, else the index of the first null character.
** RETURN VALUE
** 		The ft_strspn() function returns the number of characters spanned.
*/

static size_t	ft_strspn(const char *s, char c)
{
	size_t	span;

	span = 0;
	while (*s && (*s == c))
	{
		s++;
		span++;
	}
	return (span);
}

/*
** NAME
** 		ft_count_tokens -- count tokens in a string
** DESCRIPTION
** 		This function is used to count sequential tokens in a null-terminated
** 		string. These tokens are separated in the string by the c character.
** RETURN VALUE
** 		The function returns the amount of tokens counted in the string.
*/

static size_t	ft_count_tokens(char const *s, char c)
{
	size_t	arr_size;

	arr_size = 0;
	while ((*s == c) && (*s != '\0'))
		s++;
	while (*s)
	{
		while ((*s != c) && (*s != '\0'))
			s++;
		arr_size++;
		while ((*s == c) && (*s != '\0'))
			s++;
	}
	return (arr_size);
}

/*
** NAME
** 		ft_split -- splits string in array of strings
** DESCRIPTION
** 		Allocates (with malloc(3)) and returns an array
** 		of strings obtained by splitting ’s’ using the
** 		character ’c’ as a delimiter. The array must be
** 		ended by a NULL pointer.
** RETURN VALUE
** 		The array of new strings resulting from the split.
** 		NULL if the allocation fails.
*/

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*p;
	char	*p_start;
	size_t	i;

	p = ft_strdup(s);
	if (!p)
		return (NULL);
	arr = (char **) malloc(sizeof(char *) * (ft_count_tokens(s, c) + 1));
	if (!arr)
		return (NULL);
	p_start = p;
	i = 0;
	while (*s)
	{
		s = p + ft_strspn(p, c);
		p = (char *) s + ft_strcspn(s, c);
		if (*p != '\0')
			*p++ = '\0';
		if (*s != '\0')
			arr[i++] = ft_strdup(s);
	}
	arr[i] = NULL;
	free(p_start);
	return (arr);
}

/*
static int  flag_check(const char *str, char c, int *check)
{
	int flag;

	flag = 0;
	if (*str != c && *check == 0)
	{
		*check = 1;
		flag = 1;
	}
	else if(*str == c)
		*check = 0;
	return(flag);
}

static int  word_count(const char *str, char c)
{
	int words;
	int check;

	words = 0;
	check = 0;
	while(*str)
	{
		if(flag_check(str, c, &check))
			words++;
		str++;
	}
	return (words);
}

static int  word_fill(char **res, const char **str, char c, int word_index)
{
	int i;

	i = 0;
	while (**str && **str == c)
		(*str)++;
	while (str[0][i] && str[0][i] != c)
		i++;
	res[word_index] = ft_substr(*str, 0 , i);
	if (!res[word_index])
		return (0);
	*str = *str + i + 1;
	return (1);
}

static void free_words(char ***str, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		free(str[0][j]);
		j++;
	}
	free(*str);
	*str = NULL;
}

char    **ft_split(char const *s, char c)
{
	char **res;
	int     words;
	int     i;

	if(!s)
		return (NULL);
	i = 0;
	words = word_count(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	while (i < words)
	{
		if (!word_fill(res, &s, c, i))
		{
			free_words(&res, i);
			return (NULL);
		}
		i++;
	}
	res[words] = NULL;
	return (res);
} */
