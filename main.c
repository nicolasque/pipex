/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:33:08 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/14 21:08:04 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

size_t ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	un1;
	unsigned char	un2;

	while (n > 0)
	{
		un1 = (unsigned char )(*str1);
		un2 = (unsigned char )(*str2);
		if (un1 != un2 || *str1 == '\0')
			return (un1 - un2);
		str1 ++;
		str2 ++;
		n--;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(ft_strlen(str) + 1);
	if (new_str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// char	*find_path(char **envp)
// {
// 	while (ft_strncmp("PATH", *envp, 4))
// 		envp++;
// 	return (*envp + 5);
// }

int get_infile_fd(char **argv)
{
	int verify_fd;

	printf("infile: %s\n", argv[1]);
	verify_fd = open(argv[1], O_RDONLY, 0777);
	if (verify_fd == -1)
		return (printf("infile no valido \n"),-1);	
	return (verify_fd);
}

int	get_outfile_fd(int argc, char *argv[])
{
	int verify_fd;

	printf("outfile: %s\n", argv[argc - 1]);
	verify_fd = open(argv[argc - 1],O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (verify_fd == -1)
		return (printf("infile no valido \n"),-1);
	return (verify_fd);
}

int main(int argc, char **argv) 
{
	int pipe_fd[2];
	int fd_in;
	int fd_out;
	int pid1;
	int pid2;
	
	// 0 infile, 1 outfile
	fd_in = get_infile_fd(argv);
	fd_out = get_outfile_fd(argc, argv);
	if (fd_in == -1 || fd_out == -1)
		return (perror("algo malo con los fd"), -1);
	
	if (pipe(pipe_fd) == -1)
		return (perror("Problema con el pipe"), 1);	

	pid1 = fork();
	if (pid1 < 0)
		return (perror("Porblem wit fork 1"), 2);
	
	if (pid1 == 0)
	{//Child proces
		dup2(fd_in, 0);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		execlp(argv[2], argv[2], "-l", NULL);
		exit(1);
	}
	// Parent proces
		dup2(fd_out, 1);
		dup2(pipe_fd[0],0);
		close(pipe_fd[1]);
		execlp(argv[3], argv[3], "-l", NULL);
		exit(1);


	return (0);
}

