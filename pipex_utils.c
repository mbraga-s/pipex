/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:00:10 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/05/25 17:51:17 by mbraga-s         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	j;
	char *env;
	char **ptr;
	char *path;

	(void)argc;
	i = 0;
	j = 0;
	printf("\nEnvp:\n");
	if (access(argv[1], F_OK) != 0)
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
		ptr = ft_split(env, ':');
		while (ptr[j])
		{
			path = ft_strjoin(ptr[j], "/");
			path = ft_strjoin(path, argv[1]);
			if (access(path, F_OK) == 0)
			{
				printf("%s\n", path);
				break ;
			}
			free(path);
			j++;
		}
	}
	return (0);
}
