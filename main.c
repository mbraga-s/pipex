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
	ft_printf("Args\n");
 	if (argc != 5)
	{
		ft_printf("Wrong number of arguments.\n");
		return (0);
	}
	// create pipe
	ft_printf("Creating pipe...\n");
	if (pipe(fd) == -1)
	{
		ft_printf("Error opening pipe.\n");
		return (0);
	}
	ft_printf("Prefork\n");
	id_f1 = fork();
	if (id_f1 == 0)
	{
		// close stdin fd
		close (0);
		// open in_file, it's fd becomes the new stdin
		open (argv[1], O_RDONLY);
		// closes stdout and dups the write fd of the pipe to it
		dup2 (fd[1], 1);
		// execute cmd1 on in_file
		stuff(argv, 2);
		execve(connect(stuff(argv, 2)), stuff(argv, 2), NULL);
	}
	wait(0);
	id_f2 = fork();
	if (id_f2 == 0)
	{
		// closes stdin and dups the read fd of the pipe to it
		dup2 (fd[0], 0);
		// close stdout fd
		close (1);
		// open out_file, it's fd becomes the new stdout
		open (argv[4], O_RDONLY);
		// execute cmd2 on in_file
		execve(connect(stuff(argv, 3)), stuff(argv, 3), NULL);
	}
	return (0);
}

char	**stuff(char **argv, int l)
{
	char **ptr;
	//int i;

	//i = 1;
	ptr = ft_split(argv[l], 32);
	/* ft_printf("cmd: %s\n", ptr[0]);
	while (ptr[i])
	{
		ft_printf("args: %s\n", ptr[i]);
		i++;
	} */
	return (ptr);
}

char	*connect(char **ptr)
{
	char *path;

	path = ft_strjoin("/usr/bin/", ptr[0]);
	//ft_printf("\npath: %s\n", path);
	return (path);
}
