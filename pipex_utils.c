/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:50:52 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/17 14:54:55 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (-1); //TODO:  CAMBIAR EL PRINT POR MENSAJE DE ERROR 
		return (verify_fd);
	}
	else
	{
		verify_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (verify_fd == -1)
			return (-1); //TODO:  CAMBIAR EL PRINT POR MENSAJE DE ERROR 
		return (verify_fd);
	}
}
