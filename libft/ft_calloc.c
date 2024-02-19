/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:11:50 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/13 20:04:39 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* Esta función asigna memoria para un arreglo de nitems elementos,
* cada uno de tamaño size bytes,
* y luego escribe ceros en el espacio asignado.
*/
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*exit;

	exit = malloc(nitems * size);
	if (exit == NULL)
	{
		free(exit);
		return (NULL);
	}
	ft_bzero(exit, nitems * size);
	return (exit);
}
