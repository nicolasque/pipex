/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:46:02 by nquecedo          #+#    #+#             */
/*   Updated: 2024/10/27 18:57:19 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "../libft/libft.h"

char	*ft_find_path(char **envp);
void	ft_free_split(char **split_list);
int		get_file(char *argv, int in_out);
void	ft_error_msg(char *str);
int		ft_printf(char const *str, ...);
void	ft_exec(char *comand, char **envp);
char	*ft_get_cmd_path(char *comand, char **envp);

#endif //PIPEX_H
