/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:39:29 by nquecedo          #+#    #+#             */
/*   Updated: 2024/10/26 19:42:10 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	pid1;

	if (argc < 5 || pipe(pipe_fd) == -1)
		ft_error_msg("Pipex: error\n");
	pid1 = fork();
	if (pid1 < 0)
		ft_error_msg("Pipex: error\n");
	if (pid1 == 0)
	{
		if (ft_child(pipe_fd, argv, envp, argc) == -1)
			return (-2);
	}
	else
		ft_parent(pipe_fd, argv, envp, argc);
	return (5000);
}
