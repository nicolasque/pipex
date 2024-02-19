/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:23:16 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/18 18:57:10 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Esta función devuelve un puntero a una nueva cadena que 
* es una copia de la cadena str.
*/
char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(ft_strlen(str) + 1);
	if (new_str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
// int main()
// {
// 	char hola[] = "hola mundo";
// 	char *copia;

// 	printf("Original: %s\n", hola);

// 	copia = ft_strdup(hola);

// 	printf("Copia: %s", copia);

// 	return 0;
// }
