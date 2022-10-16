/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:06:55 by ateak             #+#    #+#             */
/*   Updated: 2021/10/25 19:38:18 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*min_int(char *str, int len)
{
	int	nbr;
	int	i;

	nbr = 147483648;
	i = len;
	while (len > 0)
	{
		str[len - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
		if (len == 2)
		{
			str[0] = '-';
			str[1] = '2';
			len = 0;
		}
	}
	str[i] = '\0';
	return (str);
}

static int	n_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	n_sign(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nbr;
	int		sign;
	int		len;
	int		i;

	sign = n_sign(n);
	nbr = n * sign;
	len = n_len(n);
	i = len;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (nbr == -2147483648)
		return (min_int(str, len));
	while (len > 0)
	{
		str[len - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	if (sign == -1)
		str[0] = '-';
	str[i] = '\0';
	return (str);
}
