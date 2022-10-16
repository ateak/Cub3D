/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:43:30 by ateak             #+#    #+#             */
/*   Updated: 2021/11/09 18:58:33 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	min_check(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	return (n);
}

static int	func_for_null_and_big_int(int n, int fd)
{
	if (n == 2147483647)
		ft_putstr_fd("2147483647", fd);
	else
		ft_putchar_fd('0', fd);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	nbr;

	i = 1;
	nbr = n;
	if (n < 0)
	{
		n = min_check(n, fd);
		nbr = n;
	}
	if (n == 0 || n == 2147483647)
		func_for_null_and_big_int(n, fd);
	while (n > 0 && n != 2147483647)
	{
		n = n / 10;
		i *= 10;
	}
	i = i / 10;
	while (i > 0)
	{
		n = nbr / i;
		ft_putchar_fd(n + '0', fd);
		nbr -= n * i;
		i /= 10;
	}
}
