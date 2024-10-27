/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:33:08 by nquecedo          #+#    #+#             */
/*   Updated: 2024/10/27 18:58:25 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_child(int pipe_fd[], char **argv, char **envp)
{
	int	fd_in;

	fd_in = get_file(argv[1], 0);
	if (fd_in == -1)
	{
		return (-1);
		ft_error_msg("Problem with infile");
	}
	dup2(fd_in, 0);
	close(fd_in);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	close(pipe_fd[0]);
	ft_exec(argv[2], envp);
	exit(0);
	return (0);
}

int	ft_parent(int pipe_fd[], char **argv, char **envp)
{
	int	fd_out;

	fd_out = get_file(argv[4], 1);
	if (fd_out == -1)
		ft_error_msg("Problem with outfile");
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

	if (argc != 5 || pipe(pipe_fd) == -1)
		ft_error_msg("Wrong number of args\n");
	pid1 = fork();
	if (pid1 < 0)
		ft_error_msg("Pipex: error\n");
	if (pid1 == 0)
	{
		if (ft_child(pipe_fd, argv, envp) == -1)
			return (-2);
	}
	else
		ft_parent(pipe_fd, argv, envp);
	return (0);
}
