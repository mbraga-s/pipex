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

/* void	cleaner(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free (argv[i]);
		i++;
	}
	free (argv);
} */

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		id_f1;
	int		id_f2;
	char	*pcmd1;
	char	*pcmd2;
	char	**args1;
	char	**args2;	

	// make sure arguments passed are okay
	if (argc != 5)
	{
		printf("Wrong number of arguments.\n");
	//	cleaner (argv);
		return (0);
	}
	args1 = args(argv, 2);
	args2 = args(argv, 3);
	pcmd1 = path(args1[0], envp);
	pcmd2 = path(args2[0], envp);
	// create pipe
	if (pipe(fd) == -1)
	{
		printf("Error opening pipe.\n");
		return (0);
	}
	id_f1 = fork();
	if (id_f1 == 0)
	{
		close(fd[0]);
		// close stdin fd
		close (0);
		// open in_file, it's fd becomes the new stdin
		open (argv[1], O_RDONLY);
		// closes stdout and dups the write fd of the pipe to it
		dup2 (fd[1], 1);
		// execute cmd1 on in_file
		execve(pcmd1, args1, envp);
	}
//	wait(0);
	id_f2 = fork();
	if (id_f2 == 0)
	{
		close(fd[1]);
		// closes stdin and dups the read fd of the pipe to it
		dup2 (fd[0], 0);
		// close stdout fd
		close (1);
		// open out_file, it's fd becomes the new stdout
		open (argv[4], O_WRONLY);
		// execute cmd2 on in_file
		execve(pcmd2, args2, envp);
		exit(0);
	}
	return (0);
}
