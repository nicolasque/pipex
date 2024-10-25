/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:05:05 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/22 16:53:57 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Esta función pone a cero (bytes con '0') los primeros n bytes
* del área de memoria apuntada por s.
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*char_s;

	char_s = (unsigned char *)s;
	while (n--)
		*char_s++ = 0;
}
