/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:24:51 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/15 15:20:05 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Esta función compara no más de n caracteres 
(caracteres que siguen a un carácter nulo no se comparan)
* de las cadenas str1 y str2. Devuelve un entero menor, 
igual o mayor que cero si str1 es respectivamente
* menor, igual o mayor que str2.
*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	un1;
	unsigned char	un2;

	while (n > 0)
	{
		un1 = (unsigned char )(*str1);
		un2 = (unsigned char )(*str2);
		if (un1 != un2 || *str1 == '\0')
			return (un1 - un2);
		str1 ++;
		str2 ++;
		n--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	// Pruebas de ft_strncmp
// 	char str1[] = "ñ";
// 	char str2[] = "";
// 	char str3[] = "Holaa";
// 	char str4[] = "Holaa";
// 	printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, 5));
// 	printf("strncmp: %d\n", strncmp(str1, str2, 5));
// 	printf("ft_strncmp: %d\n", ft_strncmp(str3, str4, 5));
// 	printf("strncmp: %d\n", strncmp(str3, str4, 5));
// 	return 0;
// }
