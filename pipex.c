/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:08:30 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/07/04 10:08:30 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		file_fd[2];
	int		status;
	int		temp;

	status = 0;
	temp = 0;
	if (argc == 5)
	{
		parse(argv, &file_fd[0], &file_fd[1], &temp);
		forking(argv, envp, file_fd, temp);
		waitpid(-1, &status, 0);
		waitpid(-1, &status, 0);
		if (temp == 1)
			unlink("temp");
		return (status);
	}
	ft_printf("Invalid number of arguments");
	return (1);
}

void	forking(char **argv, char **envp, int *file_fd, int temp)
{
	int		fd[2];
	int		id[2];

	if (pipe(fd) == -1)
	{
		perror(NULL);
		exit(1);
	}
	id[0] = fork();
	if (id[0] == -1)
		perror(NULL);
	if (id[0] == 0)
	{
		if (temp == 1)
			exit(1);
		first_fork(argv, envp, fd, file_fd);
	}
	id[1] = fork();
	if (id[1] == -1)
		perror(NULL);
	if (id[1] == 0)
		second_fork(argv, envp, fd, file_fd);
	close_fd(fd);
	close_fd(file_fd);
}

void	first_fork(char **argv, char **envp, int *fd, int *file_fd)
{
	char	*path;
	char	**args;
	int		i;
	int		dups[2];

	i = 0;
	args = ft_split(argv[2], 32);
	path = check_path(args[0], envp);
	dups[0] = dupcheck(file_fd[0], 0);
	dups[1] = dupcheck(fd[1], 1);
	close_fd(fd);
	close_fd(file_fd);
	if (path)
		execve(path, args, envp);
	close_fd(dups);
	while (args[i])
		free(args[i++]);
	free(args);
	free(path);
	exit(1);
}

void	second_fork(char **argv, char **envp, int *fd, int *file_fd)
{
	char	*path;
	char	**args;
	int		i;
	int		dups[2];

	i = 0;
	args = ft_split(argv[3], 32);
	path = check_path(args[0], envp);
	dups[0] = dupcheck(fd[0], 0);
	dups[1] = dupcheck(file_fd[1], 1);
	close_fd(fd);
	close_fd(file_fd);
	if (path)
		execve(path, args, envp);
	close_fd(dups);
	while (args[i])
		free(args[i++]);
	free(args);
	free(path);
	exit(1);
}
