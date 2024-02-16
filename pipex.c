/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:33:08 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/16 20:47:34 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pipex.h"

size_t	ft_strlen(char *str)
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

char	*ft_find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	ft_free_split(char **split_list)
{
	int	i;

	i = 0;
	while (split_list[i])
	{
		free(split_list[i]);
		i++;
	}
	free(split_list);
}

// int get_infile_fd(char **argv)
// {
// 	int verify_fd;
// 	printf("infile: %s\n", argv[1]);
// 	verify_fd = open(argv[1], O_RDONLY, 0777);
// 	if (verify_fd == -1)
// 		return (printf("infile no valido \n"),-1);	
// 	return (verify_fd);
// }
// int	get_outfile_fd(int argc, char *argv[])
// {
// 	int verify_fd;
// 	printf("outfile: %s\n", argv[argc - 1]);
// 	verify_fd = open(argv[argc - 1],O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	if (verify_fd == -1)
// 		return (printf("infile no valido \n"),-1);
// 	return (verify_fd);
// }

int	get_file(char **argv, int argc, int in_out)
{
	int	verify_fd;

	if (in_out == 0)
	{
		verify_fd = open(argv[1], O_RDONLY, 0777);
		if (verify_fd == -1)
			return (printf("infile no valido \n"), -1); //TODO:  CAMBIAR EL PRINT POR MENSAJE DE ERROR 
		return (verify_fd);
	}
	else
	{
		verify_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (verify_fd == -1)
			return (printf("infile no valido \n"), -1); //TODO:  CAMBIAR EL PRINT POR MENSAJE DE ERROR 
		return (verify_fd);
	}
}

char	*ft_get_cmd_path(char *comand, char **envp)
{
	int		i;
	char	**path_split;
	char	**comand_split;
	char	*path_try;
	char	*path_exec;
	
	path_split = ft_split(ft_find_path(envp), ':');
	comand_split = ft_split(comand, ' ');
	i = 0;
	while (path_split[i])
	{
		path_try = ft_strjoin(path_split[i], "/");
		path_exec = ft_strjoin(path_try, comand_split[0]);
		free(path_try);
		if (access(path_exec, F_OK | X_OK) == 0)
		{
			ft_free_split(comand_split);
			return (path_exec);
 		}
		free(path_exec);
		i++;
	}
	ft_free_split(comand_split);
	ft_free_split(path_split);
	return (comand);
}

void	ft_exec(char *comand, char **envp)
{
	char	**comand_split;

	comand_split = ft_split(comand, ' ');
	if (execve(ft_get_cmd_path(comand_split[0], envp), comand_split, envp) == -1)
	{
		perror("comando no encontrado: \n");
		ft_free_split(comand_split);
		exit(2);
	}
}

int main(int argc, char **argv, char **envp) 
{
	int pipe_fd[2];
	int fd_in;
	int fd_out;
	int pid1;
	
	fd_in = get_file(argv, argc, 0);
	fd_out = get_file(argv, argc, 1);
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
		// execlp(argv[2], argv[2], "-l", NULL);
		ft_exec(argv[2], envp);
		exit(0);
	}
	// Parent proces
		dup2(fd_out, 1);
		dup2(pipe_fd[0],0);
		close(pipe_fd[1]);
		// execlp(argv[3], argv[3], "-l", NULL);
		ft_exec(argv[3], envp);
	close(fd_in);
	close(fd_out);

	return (0);
}

