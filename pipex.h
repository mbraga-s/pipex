/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:00:50 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/07/10 14:56:26 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_fd
{
	int		infile;
	int		outfile;
	char	*path;	
}				t_fd;

char	**ft_split(char const *s, char c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *str);

void	*ft_calloc(size_t nmemb, size_t size);

void	ft_bzero(void *s, size_t n);

char	*ft_substr(const char *s, unsigned int start, size_t len);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int		ft_printf(const char *str, ...);

void	ft_hex(long unsigned int c, int *len);

void	ft_putchar(int c, int *len);

void	ft_putnbr(int n, int *len);

void	ft_putnbrhex(unsigned int c, int *len);

void	ft_putptr(void *s, int *len);

void	ft_putstr(const char *s, int *len);

void	ft_unsputnbr(unsigned int n, int *len);

void	ft_upperputnbrhex(unsigned int c, int *len);

char	*ft_strdup(const char *s);

void	*ft_memcpy(void *dest, const void *src, size_t n);

char	**args(char **argv, int l);

char	*check_path(char *arg, char **envp);

void	parse(char **argv, int *infile_fd, int *outfile_fd, int *flag);

void	forking(char **argv, char **envp, int *file_fd, int temp);

void	first_fork(char **argv, char **envp, int *fd, int *file_fd);

void	second_fork(char **argv, char **envp, int *fd, int *file_fd);

int		pcheck(char *ptr);

char	*pathtest(char *env, char *arg);

void	close_fd(int *fd);

int		dupcheck(int file_fd, int fd);

#endif