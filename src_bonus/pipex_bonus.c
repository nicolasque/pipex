/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:39:29 by nquecedo          #+#    #+#             */
/*   Updated: 2024/10/27 19:00:39 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	here_doc_put_in(char **av, int *p_fd)
{
	char	*ret;

	close(p_fd[0]);
	while (1)
	{
		ret = get_next_line(0);
		if (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0)
		{
			free(ret);
			exit(0);
		}
		ft_putstr_fd(ret, p_fd[1]);
		free(ret);
	}
}

void	manaje_here_doc(char **av)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
		here_doc_put_in(av, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		wait(NULL);
	}
}

void	do_pipe(char *cmd, char **env)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		ft_exec(cmd, env);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	i;

	if (argc < 5)
		ft_error_msg("Pipex: error\n");
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		i = 3;
		if (argc < 6)
			ft_error_msg("Pipex: error\n");
		fd_out = get_file(argv[argc - 1], 2);
		manaje_here_doc(argv);
	}
	else
	{
		i = 2;
		fd_in = get_file(argv[1], 0);
		fd_out = get_file(argv[argc - 1], 1);
		dup2(fd_in, 0);
	}
	while (i < argc - 2)
		do_pipe(argv[i++], envp);
	dup2(fd_out, 1);
	return (ft_exec(argv[argc - 2], envp), 000);
}
