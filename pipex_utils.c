/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:00:10 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/05/26 17:33:33 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* int	parsing(char **argv)
{
	if (access(argv[1], F_OK) < 0 || access(argv[4], F_OK) < 0)
	{
		cleaner(argv);
		exit(0);
	}
	
} */

char	**args(char **argv, int l)
{
	char	**ptr;

	ptr = ft_split(argv[l], 32);
	return (ptr);
}


char	*path(char *arg, char **envp)
{
	int	i;

	char *env;
	char **ptr;
	char *path;

	i = 0;
	if (pcheck(arg) == 0)
	{
		while (envp[i])
		{
			if (!ft_strncmp("PATH=", envp[i],5))
			{
				env = envp[i] + 5;
				break ;
			}
			i++;
		}
		i = 0;
		ptr = ft_split(env, ':');
		while (ptr[i])
		{
			path = ft_strjoin(ptr[i], "/");
			path = ft_strjoin(path, arg);
			if (access(path, F_OK) == 0)
			{
				//printf("%s\n", path);
				return (path);
				break ;
			}
			free(path);
			i++;
		}
	}
	return (arg);
}

int	pcheck(char *ptr)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (ptr[i])
	{
		if (ptr[i] == '/')
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}
