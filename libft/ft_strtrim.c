/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:24:58 by ateak             #+#    #+#             */
/*   Updated: 2021/11/10 14:35:59 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_malloc_if_end_of_str(size_t size)
{
	char	*s;
	char	*new_str;
	size_t	i;

	s = "";
	new_str = (char *)malloc(size);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < 1)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static size_t	start_str(char const *s1, char const *set, size_t set_len)
{
	char	*str1;
	char	*set2;
	size_t	i;
	size_t	j;

	str1 = (char *)s1;
	set2 = (char *)set;
	i = 0;
	j = 0;
	while (str1[i])
	{
		while (set2[j] != str1[i] && j <= set_len)
		{
			j++;
			if (j == set_len)
				return (i);
		}
		i++;
		j = 0;
	}
	if (str1[i] == '\0')
		return (i);
	return (0);
}

static size_t	end_str(char const *s1, char const *set, size_t set_len)
{
	char	*str1;
	char	*set2;
	size_t	i;
	size_t	j;
	size_t	m;

	str1 = (char *)s1;
	set2 = (char *)set;
	i = ft_strlen(str1) - 1;
	j = 0;
	m = 0;
	while (i >= 0 && str1[m])
	{
		while (set2[j] != str1[i] && j <= set_len)
		{
			j++;
			if (j == set_len)
				return (i);
		}
		m++;
		i--;
		j = 0;
	}
	return (0);
}

static char	*stuff_new_str(char *new_str, char const *s1, size_t newstr_len,
size_t start_trimstr)
{
	size_t	i;

	i = 0;
	while (i < newstr_len)
	{
		new_str[i] = ((char *)s1)[start_trimstr];
		start_trimstr++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	start_trimstr;
	size_t	end_trimstr;
	size_t	set_len;
	size_t	newstr_len;

	if (!s1)
		return (NULL);
	set_len = ft_strlen((char *)set);
	if (set[0] == '\0')
		set_len = 1;
	start_trimstr = start_str(s1, set, set_len);
	if (start_trimstr == ft_strlen((char *)s1))
		return (ft_malloc_if_end_of_str(sizeof(char) * 2));
	end_trimstr = end_str(s1, set, set_len);
	newstr_len = end_trimstr - start_trimstr + 1;
	new_str = (char *)malloc(newstr_len + 1);
	if (new_str == NULL)
		return (NULL);
	new_str = stuff_new_str(new_str, s1, newstr_len, start_trimstr);
	return (new_str);
}
