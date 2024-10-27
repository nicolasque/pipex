/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:50:52 by nquecedo          #+#    #+#             */
/*   Updated: 2024/10/27 19:00:23 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

int	get_file(char *argv, int in_out)
{
	int	verify_fd;

	if (in_out == 0)
		verify_fd = open(argv, O_RDONLY, 0644);
	else if (in_out == 1)
		verify_fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		verify_fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (verify_fd == -1)
		return (-1);
	return (verify_fd);
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
