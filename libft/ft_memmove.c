/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:20:48 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/12 19:43:48 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Esta función copia n bytes desde src a dest. 
* Las dos cadenas pueden superponerse;
* la copia se realiza de manera no destructiva. Devuelve un puntero a dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;

	char_src = (unsigned char *)src;
	char_dest = (unsigned char *)dest;
	if ((dest == NULL && src == NULL) && count > 0)
		return (NULL);
	if (char_dest < char_src)
	{
		while (count--)
			*char_dest++ = *char_src++;
	}
	else
	{
		char_dest += count;
		char_src += count;
		while (count--)
			*(--char_dest) = *(--char_src);
	}
	return (dest);
}
