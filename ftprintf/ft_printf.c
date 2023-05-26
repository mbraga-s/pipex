/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:13:08 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/05/26 15:56:02 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_params(va_list arg, const char *str, int i, int *len)
{
	if (str[i] == 'c')
		ft_putchar (va_arg(arg, int), len);
	else if (str[i] == 's')
		ft_putstr (va_arg(arg, char *), len);
	else if (str[i] == 'p')
		ft_putptr (va_arg(arg, void *), len);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr (va_arg(arg, int), len);
	else if (str[i] == 'u')
		ft_unsputnbr (va_arg(arg, unsigned int), len);
	else if (str[i] == 'x')
		ft_putnbrhex(va_arg(arg, long unsigned int), len);
	else if (str[i] == 'X')
		ft_upperputnbrhex(va_arg(arg, unsigned int), len);
	else if (str[i] == '%')
		ft_putchar (str[i], len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		flag;
	int		len;

	va_start (arg, str);
	i = 0;
	len = 0;
	flag = 0;
	while (str[i])
	{
		if (flag == 1)
		{
			ft_params (arg, str, i, &len);
			flag = 0;
		}
		else if (str[i] == '%' && flag == 0)
			flag = 1;
		else
			ft_putchar (str[i], &len);
		i++;
	}
	va_end (arg);
	return (len);
}
