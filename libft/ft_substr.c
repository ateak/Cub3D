/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:25:20 by ateak             #+#    #+#             */
/*   Updated: 2021/11/10 16:29:25 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	static	substr_len(char *str, unsigned int start, size_t len)
{
	unsigned int	j;
	size_t			m;

	j = start;
	m = 0;
	while (str[j] && m < len)
	{
		j++;
		m++;
	}
	return (m);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*substr;
	size_t			size;
	size_t			i;

	str = (char *)s;
	if (!str)
		return (NULL);
	if ((unsigned char)ft_strlen(str) < start || len == 0)
		return (ft_strdup(""));
	size = substr_len(str, start, len) + 1;
	substr = (char *)malloc(size);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (str[start] != '\0' && len > 0)
	{
		substr[i] = str[start];
		i++;
		start++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
