/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:01:11 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/17 22:01:40 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_touper_wraper(unsigned int i, char *c)
// {
// 	i ++;
// 	*c = (char)ft_toupper(*c);
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
// int main()
// {
// 	char s[] = "hola";
// 	printf("Antes: %s\n", s);
// 	ft_striteri(s, ft_touper_wraper);
// 	printf("Despues: %s\n", s);
// 	return 0;
// }
