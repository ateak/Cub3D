/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:26:08 by ateak             #+#    #+#             */
/*   Updated: 2021/10/19 19:49:42 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;
	int				c;

	str = (unsigned char *)s;
	c = 0;
	if (n == 0)
		return ;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
}
