/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:25:30 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/19 20:40:16 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Esta función devuelve una copia de s1 con los
* caracteres especificados en set eliminados
* del principio y del final de la cadena.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*exit;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	len = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (start == len + 1)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[len]))
		len --;
	exit = ft_substr(s1, start, len - start + 1);
	if (!exit)
		return (NULL);
	return (exit);
}
