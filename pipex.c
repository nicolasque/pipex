/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:33:08 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/20 19:27:28 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	char	*cmd_path;

	comand_split = ft_split(comand, ' ');
	cmd_path = ft_get_cmd_path(comand_split[0], envp);
	if (execve(cmd_path, comand_split, envp) == -1)
	{
		perror("Pipex:");
		ft_free_split(comand_split);
		exit(-2);
	}
}

int	ft_child(int pipe_fd[], char **argv, char **envp, int argc)
{
	int	fd_in;

	fd_in = get_file(argv, argc, 0);
	if (fd_in == -1)
		return (perror("Pipex"), -1);
	dup2(fd_in, 0);
	close(fd_in);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	close(pipe_fd[0]);
	ft_exec(argv[2], envp);
	exit(0);
	return (0);
}

int	ft_parent(int pipe_fd[], char **argv, char **envp, int argc)
{
	int	fd_out;

	fd_out = get_file(argv, argc, 1);
	if (fd_out == -1)
		return (perror("Pipex"), -1);
	dup2(fd_out, 1);
	close(fd_out);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	ft_exec(argv[3], envp);
	close(fd_out);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	pid1;
	int status;

	if (argc != 5)
		exit(130);
	if (pipe(pipe_fd) == -1)
		exit(-1);
	pid1 = fork();
	if (pid1 < 0)
		exit(-1);
	if (pid1 == 0)
	{
		if (ft_child(pipe_fd, argv, envp, argc) == -1)
			return (-2);
	}
	else
	{
		waitpid(pid1, &status, 0);
		ft_parent(pipe_fd, argv, envp, argc);
	}
	return (0);
}
