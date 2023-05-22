/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:32:23 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/05/16 17:32:23 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>


char	**stuff(char **argv, int l);
char	*connect(char **ptr);

int	main(int argc, char **argv)
{
	int	fd[2];
	int	id_f1;
	int	id_f2;

	// make sure arguments passed are okay
 	if (argc != 5)
	{
		ft_printf("Wrong number of arguments.\n");
		return (0);
	}
	// create pipe
	if (pipe(fd) == -1)
	{
		ft_printf("Error opening pipe.\n");
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
		//dup2 (fd[1], 1);
		close (1);
		dup (fd[1]);
		// execute cmd1 on in_file
		execve(connect(stuff(argv, 2)), stuff(argv, 2), NULL);
	}
//	wait(0);
	id_f2 = fork();
	if (id_f2 == 0)
	{
		close(fd[1]);
		// closes stdin and dups the read fd of the pipe to it
		//dup2 (fd[0], 0);
		close (0);
		dup (fd[0]);
		// close stdout fd
		close (1);
		// open out_file, it's fd becomes the new stdout
		open (argv[4], O_WRONLY);
		// execute cmd2 on in_file
		execve(connect(stuff(argv, 3)), stuff(argv, 3), NULL);
		exit(0);
	}
	exit (0);
	return (0);
}

char	**stuff(char **argv, int l)
{
	char **ptr;

	ptr = ft_split(argv[l], 32);
	return (ptr);
}

char	*connect(char **ptr)
{
	char *path;

	path = ft_strjoin("/usr/bin/", ptr[0]);
	return (path);
}
