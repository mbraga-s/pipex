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
	int		infile_fd; //add to struct
	int		outfile_fd; //add to struct

	// initialise struct
	if (argc != 5)
	{
		ft_printf("Invalid number of arguments");
		exit(0);
	}
	parse(argv, &infile_fd, &outfile_fd);
	forking(argv, infile_fd, outfile_fd, envp);
	return (0);
}

void	forking(char **argv, int infile_fd, int outfile_fd, char **envp)
{
	char	**args;
	int		fd[2];
	int		id_f1;
	int		id_f2;
	char	*path; //add to struct

	path = NULL; //temp
	if (pipe(fd) == -1)
	{
		printf("Error opening pipe.\n");
	}
	id_f1 = fork();
	if (id_f1 == 0)
	{	
		close(fd[0]);
		args = ft_split(argv[2], 32);
		path = check_path(args[0], envp);
		dup2(infile_fd, 0);
		dup2 (fd[1], 1);
		execve(path, args, envp);
	}
	id_f2 = fork();
	if (id_f2 == 0)
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
