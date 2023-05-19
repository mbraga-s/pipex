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
		// close stdin fd
		close (0);
		// open in_file, it's fd becomes the new stdin
		open (argv[2], O_RDONLY);
		// closes stdout and dups the write fd of the pipe to it
		dup2 (1, fd[1]);
		// execute cmd1 on in_file
		execve()
	}
	id_f2 = fork();
	if (id_f2 == 0)
	{
		// closes stdin and dups the read fd of the pipe to it
		dup2 (0, fd[0]);
		// close stdout fd
		close (1);
		// open out_file, it's fd becomes the new stdout
		open (argv[3], O_RDONLY);
		execve()
	}
	waitpid (id_f1);
	waitpid (id_f2);
	return (0);
}
