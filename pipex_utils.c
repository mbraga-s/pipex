/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:00:10 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/06/14 00:17:36 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse(char **argv, int *infile_fd, int *outfile_fd)
{
	*infile_fd = open(argv[1], O_RDONLY);
	if (*infile_fd < 0)
	{
		perror(argv[1]);
		exit(0);
	}
	*outfile_fd = open(argv[4], O_CREAT | O_RDWR); // | O_TRUNC, 0644); find out why this first
	if (*outfile_fd < 0)
	{
		perror(argv[4]);
		exit(0);
	}
}

char	**args(char **argv, int l)
{
	char	**ptr;

	ptr = ft_split(argv[l], 32);
	return (ptr);
}


char	*check_path(char *arg, char **envp)
{
	int		i;
	char	*env;
	char	**ptr;
	char	*path;

	i = 0;
	if (pcheck(arg) == 0)
	{
		while (envp[i])
		{
			if (!ft_strncmp("PATH=", envp[i], 5))
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
			if (access(path, X_OK) == 0)
			{
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
