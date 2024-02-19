/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:17:40 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/12 19:44:49 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Esta función compara los primeros n bytes de las cadenas str1 y str2.
* Devuelve un entero menor, igual o mayor que cero si str1 es
* respectivamente menor, igual o mayor que str2.
*/
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*char_str1;
	unsigned char	*char_str2;

	char_str1 = (unsigned char *)str1;
	char_str2 = (unsigned char *)str2;
	while (n--)
	{
		if (*char_str1 != *char_str2)
			return (*char_str1 - *char_str2);
		char_str1++;
		char_str2++;
	}
	return (0);
}
