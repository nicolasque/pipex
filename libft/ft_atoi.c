/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:04:31 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/13 19:09:52 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' \
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

/*
* Esta función convierte la cadena inicial en str a un valor int.
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	minus_counter;
	int	exit;
	int	sum_count;

	i = 0;
	minus_counter = 0;
	sum_count = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			minus_counter++;
		else
			sum_count++;
		if ((minus_counter + sum_count) > 1)
			return (0);
	}
	exit = 0;
	while (ft_isdigit(str[i]))
		exit = 10 * exit + (str[i++] - '0');
	if (minus_counter)
		return (-exit);
	return (exit);
}
