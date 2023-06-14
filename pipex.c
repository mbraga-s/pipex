/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:27:13 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/05/23 16:27:13 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* t_fd	*init(t_fd	*fdesc)
{
	fdesc->path = NULL;
	fdesc->infile = 0;
	fdesc->outfile = 0;
	return (fdesc);
}
 */

int	main(int argc, char **argv, char **envp)
{
	int		infile_fd;
	int		outfile_fd;

	if (argc != 5)
	{
		ft_printf("Invalid number of arguments");
		exit(0);
	}
	parse(argv, &infile_fd, &outfile_fd);
	forking(argv, envp, infile_fd, outfile_fd);
	return (0);
}

void	forking(char **argv, char **envp, int infile_fd, int outfile_fd)
{
	int		fd[2];

	if (pipe(fd) == -1)
	{
		printf("Error opening pipe.\n");
		exit(0);
	}
	first_fork(argv, envp, fd, infile_fd);
	wait(NULL);
	second_fork(argv, envp, fd, outfile_fd);
}

void	first_fork(char **argv, char **envp, int *fd, int infile_fd)
{
	int		id;
	char	*path;
	char	**args;

	id = fork();
	if (id == 0)
	{	
		close(fd[0]);
		args = ft_split(argv[2], 32);
		path = check_path(args[0], envp);
		dup2(infile_fd, 0);
		dup2 (fd[1], 1);
		execve(path, args, envp);
	}
}

void	second_fork(char **argv, char **envp, int *fd, int outfile_fd)
{
	int		id;
	char	*path;
	char	**args;

	id = fork();
	if (id == 0)
	{
		close(fd[1]);
		args = ft_split(argv[3], 32);
		path = check_path(args[0], envp);
		dup2 (fd[0], 0);
		dup2(outfile_fd, 1);
		execve(path, args, envp);
		exit(0);
	}
}
