/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:16:57 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/12 19:45:20 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Esta función busca el primer carácter c 
* (convertido a un unsigned char) en los primeros n bytes
* de la cadena str. Devuelve un puntero al carácter coincidente,
* o NULL si no se encontró el carácter.
*/
void	*ft_memchr(const void *str, int c, size_t n)
{
	char	char_c;
	char	*char_str;

	char_c = c;
	char_str = (char *)str;
	while (n--)
	{
		if (*char_str == char_c)
			return (char_str);
		char_str++;
	}
	return (NULL);
}
