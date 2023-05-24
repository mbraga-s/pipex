/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:22:07 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/05/24 18:22:07 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <fcntl.h>
#include "libft.h"

int	parsing(char **argv)
{
	if (access(argv[1], F_OK) < 0 || access(argv[4], F_OK) < 0)
	{
		cleaner(argv);
		exit(0);
	}
	
}

void	cleaner(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free (argv[i]);
		i++;
	}
	free (argv);
}

char	*stuff(char **argv)
{
	char	**ptr;
	int		i;
	char	*path;

	i = 1;
	ptr = ft_split(argv[2], 32);
	ft_printf("cmd: %s\n", ptr[0]);
	while (ptr[i])
	{
		ft_printf("args: %s\n", ptr[i]);
		i++;
	}
	path = ft_strjoin("/usr/bin/", ptr[0]);
	ft_printf("\npath: %s\n", path);
	i = 0;
	//free split array and each word
	while (ptr[i])
	{
		free (ptr[i]);
		i++;
	}
	free (ptr);
	free(path);
	return (0);
}
