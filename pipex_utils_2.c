/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:20:12 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/07/10 14:23:06 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	dupcheck(int file_fd, int fd)
{
	int	i;

	i = 0;
	i = dup2(file_fd, fd);
	if (i == -1)
	{
		exit(1);
	}
}
