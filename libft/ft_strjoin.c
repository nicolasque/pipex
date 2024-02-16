/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:23:44 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/16 19:37:12 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Esta función concatena dos cadenas de caracteres.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*exit;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	exit = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (exit == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		exit[i++] = *s1++;
	while (*s2)
		exit[i++] = *s2++;
	exit[i] = '\0';
	return (exit);
}
