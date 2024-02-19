/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:25:49 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/14 10:42:32 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Esta función devuelve una cadena de caracteres que es
* una subcadena de la cadena s.
* La subcadena comienza en el índice start y tiene un tamaño máximo de len.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;

	if (s == NULL)
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	output = malloc(len * sizeof(char) + 1);
	if (output == NULL)
		return (NULL);
	ft_strlcpy(output, s + start, len + 1);
	return (output);
}
