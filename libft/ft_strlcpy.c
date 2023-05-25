/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:46:10 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/05/25 17:42:12 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)src;
	if (size > 0)
	{
		while ((size - 1) > i && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(ptr));
}
