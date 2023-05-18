/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:48:55 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/05/16 17:50:49 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);

void	ft_hex(long unsigned int c, int *len);

void	ft_putchar(int c, int *len);

void	ft_putnbr(int n, int *len);

void	ft_putnbrhex(unsigned int c, int *len);

void	ft_putptr(void *s, int *len);

void	ft_putstr(const char *s, int *len);

void	ft_unsputnbr(unsigned int n, int *len);

void	ft_upperputnbrhex(unsigned int c, int *len);

#endif