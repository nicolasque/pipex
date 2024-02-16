/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:21:46 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/16 13:50:50 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_splits(char const *s, char c)
{
	int	count;
	int	bool_in_word;

	count = 0;
	bool_in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (bool_in_word == 0)
			{
				count++;
				bool_in_word = 1;
			}
		}
		else
			bool_in_word = 0;
		s++;
	}
	return (count);
}

static int	ft_sub_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

static char	**ft_free_mem(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i--]);
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		splits;
	int		i;
	int		len;
	char	**result;

	splits = ft_count_splits(s, c);
	result = (char **)malloc((splits + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < splits)
	{
		while (*s == c)
			s++;
		len = ft_sub_len(s, c);
		result[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!result[i])
			return (ft_free_mem(result, i));
		ft_strlcpy(result[i], s, len + 1);
		s += len;
		i++;
	}
	result[splits] = NULL;
	return (result);
}


// #include <stdio.h>
// int main()
// {
// 	char **p = ft_split("three words apart", ' ');
// 	while (*p)
// 	{
// 		printf("%s ", *p);
// 		p++;
// 	}
// 	printf("%s\n", *p);
// }
