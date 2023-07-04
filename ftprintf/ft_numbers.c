/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:21:10 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/07/04 10:09:34 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_putnbr(int n, int *len)
{
	char	c;

	if (n == INT_MIN)
	{
		ft_putstr("-2", len);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar ('-', len);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr ((n / 10), len);
		n = n % 10;
	}
	if (n <= 9 && n >= 0)
	{
		c = (48 + n);
		ft_putchar (c, len);
	}
}

void	ft_unsputnbr(unsigned int n, int *len)
{
	char	c;

	if (n > 9)
	{
		ft_unsputnbr((n / 10), len);
		n = n % 10;
	}
	if (n <= 9)
	{
		c = (48 + n);
		ft_putchar (c, len);
	}
}

void	ft_putnbrhex(unsigned int c, int *len)
{
	char	*ptr;

	ptr = "0123456789abcdef";
	if (c < 16)
	{
		ft_putchar (ptr[c], len);
	}
	if (c >= 16)
	{
		ft_putnbrhex (c / 16, len);
		ft_putnbrhex (c % 16, len);
	}
}

void	ft_upperputnbrhex(unsigned int c, int *len)
{
	char	*ptr;

	ptr = "0123456789ABCDEF";
	if (c < 16)
	{
		ft_putchar (ptr[c], len);
	}
	if (c >= 16)
	{
		ft_upperputnbrhex (c / 16, len);
		ft_upperputnbrhex (c % 16, len);
	}
}
