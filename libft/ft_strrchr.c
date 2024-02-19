/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:25:16 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/19 20:40:46 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Esta función busca el último carácter c 
* (convertido a un char) en la cadena str.
* Devuelve un puntero al carácter coincidente, 
* o NULL si no se encontró el carácter.
*/
char	*ft_strrchr(const char *str, unsigned char c)
{
	int	i;

	i = ft_strlen(str);
	str += i;
	while (i-- >= 0)
	{
		if (*str == c)
			return ((char *)str);
		str --;
	}
	return (NULL);
}
