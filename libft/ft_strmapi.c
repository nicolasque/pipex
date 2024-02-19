/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:57:31 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/19 20:41:34 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	str_len;
	unsigned int	i;
	char			*cast_s;

	str_len = ft_strlen(s);
	cast_s = malloc(str_len + 1 * sizeof(char));
	if (!cast_s)
		return (NULL);
	ft_strlcpy(cast_s, s, str_len + 1);
	i = 0;
	while (i < str_len)
	{
		cast_s[i] = f(i, s[i]);
		i++;
	}
	return (cast_s);
}
// char	ft_cifrate(unsigned int c, char key)
// {
// 	c = c + (key - 'a');
// 	return ((char )c);
// }
// char ft_toupper_wraper(unsigned int i, char c)
// {
// 	i++;
// 	return(ft_toupper(c));
// }
// int main()
// {
// 	// printf("a + c = %c", ft_cifrate('a', 'c'));
// 	printf("la salida es: %s", ft_strmapi("hola", ft_toupper_wraper));
// 	return 0;
// }
