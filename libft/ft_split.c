/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:25:55 by ateak             #+#    #+#             */
/*   Updated: 2021/11/10 18:05:47 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	**ft_free(char **arr, size_t m)
{
	size_t	i;

	i = 0;
	while (i < m)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}

static char	**malloc_for_words(char const *s, char c)
{
	size_t	i;
	size_t	words_nbr;
	char	**words_arr;

	i = 0;
	words_nbr = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			if (s[i] == c || s[i] == '\0')
				words_nbr++;
		}
	}
	words_arr = (char **)malloc(sizeof(char *) * (words_nbr + 1));
	return (words_arr);
}

static char	**malloc_for_elem(char const *s, char c, char **split_arr, size_t i)
{
	size_t	m;
	size_t	elem_nbr;

	m = 0;
	elem_nbr = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			elem_nbr++;
			i++;
		}
		if (elem_nbr > 0)
		{
			split_arr[m] = (char *)malloc(sizeof(char) * (elem_nbr + 1));
			if (split_arr[m] == NULL)
				return ((char **)ft_free(split_arr, m));
			elem_nbr = 0;
			m++;
		}
	}
	return (split_arr);
}

static char	**stuff_split_arr(char const *s, char c, char **split_arr, size_t i)
{
	size_t	m;
	size_t	n;

	m = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			split_arr[m][n] = s[i];
			i++;
			n++;
		}
		if (n > 0)
		{
			split_arr[m][n] = '\0';
			n = 0;
			m++;
		}
	}
	split_arr[m] = NULL;
	return (split_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**split_arr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	split_arr = malloc_for_words(s, c);
	if (split_arr == NULL)
		return (NULL);
	split_arr = malloc_for_elem(s, c, split_arr, i);
	split_arr = stuff_split_arr(s, c, split_arr, i);
	return (split_arr);
}
