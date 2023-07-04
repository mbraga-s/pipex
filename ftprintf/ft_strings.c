/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:27:12 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/07/04 10:09:19 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_putchar(int c, int *len)
{
	write (1, &c, 1);
	(*len)++;
}

void	ft_hex(long unsigned int c, int *len)
{
	char	*ptr;

	ptr = "0123456789abcdef";
	if (c < 16)
	{
		ft_putchar (ptr[c], len);
	}
	if (c >= 16)
	{
		ft_hex (c / 16, len);
		ft_hex (c % 16, len);
	}
}

void	ft_putptr(void *s, int *len)
{
	long unsigned int	i;

	if (!s)
		ft_putstr ("(nil)", len);
	else
	{
		ft_putstr ("0x", len);
		i = (long unsigned int)s;
		ft_hex (i, len);
	}
}

void	ft_putstr(const char *s, int *len)
{
	unsigned int	i;

	i = 0;
	if (!s)
		ft_putstr ("(null)", len);
	else
		while (s[i])
			ft_putchar (s[i++], len);
}
