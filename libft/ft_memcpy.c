/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:18:48 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/13 16:46:14 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Esta función copia n bytes desde el área de memoria src
* al área de memoria dest.
* Si dest y src se superponen, el comportamiento es indefinido.
* Devuelve un puntero a dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;

	if ((dest == NULL && src == NULL) && n > 0)
		return (NULL);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	while (n--)
		*char_dest++ = *char_src++;
	return (dest);
}
