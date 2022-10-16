/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:24:06 by ateak             #+#    #+#             */
/*   Updated: 2021/10/19 19:52:16 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;
	size_t	j;
	size_t	amount;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	i = 0;
	j = 0;
	amount = 0;
	if (s2[0] == '\0')
		return (s1);
	while (s2[amount])
		amount++;
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] && s2[j] && s1[i + j] == s2[j] && i + j < len)
			j++;
		if (j == amount)
			return (&s1[i]);
		i++;
	}
	return (0);
}
