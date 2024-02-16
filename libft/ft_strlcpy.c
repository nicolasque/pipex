/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:24:27 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/19 16:27:16 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Esta función copia hasta size - 1 caracteres de la cadena de origen a dest,
* añadiendo un carácter nulofinal. 
* Devuelve la longitud total de la cadena que intentó crear,
* que es la longitud de src.
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size > 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
		size--;
	}
	if (size != 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
