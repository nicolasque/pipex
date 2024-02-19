/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:57:26 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/04 18:24:44 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (str[len])
			len++;
		write(1, str, len);
	}
	return (len);
}

static int	ft_print_pointer(char *base, size_t nbr, int print_prefix)
{
	size_t	print_len;
	size_t	base_len;

	print_len = 0;
	base_len = 0;
	if (print_prefix)
		print_len += ft_print_str("0x");
	while (base[base_len])
		base_len++;
	if (nbr < base_len)
		write(1, &base[nbr], 1);
	else
	{
		print_len += ft_print_pointer(base, nbr / base_len, 0);
		write(1, &base[nbr % base_len], 1);
		print_len ++;
	}
	return (print_len);
}

static int	ft_print_num_base(char *base, long nbr)
{
	int	base_len;
	int	print_len;

	print_len = 1;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		print_len += ft_print_str("-");
		nbr *= -1;
	}
	if (nbr < base_len)
		write(1, &base[nbr], 1);
	else
	{
		print_len += ft_print_num_base(base, nbr / base_len);
		write(1, &base[nbr % base_len], 1);
	}
	return (print_len);
}

static int	ft_detect_converters(char *str, va_list args)
{
	if (*str == '%')
	{
		if (*(str + 1) == 'c')
			return (write(1, &(char){va_arg(args, int)}, 1));
		else if (*(str + 1) == 's')
			return (ft_print_str(va_arg(args, void *)));
		else if (*(str + 1) == 'p')
			return (ft_print_pointer(HEXA_LO, \
			(size_t)va_arg(args, void *), 1) + 1);
		else if (*(str + 1) == 'd' || *(str + 1) == 'i')
			return (ft_print_num_base(DEC_DIGS, va_arg(args, int)));
		else if (*(str + 1) == 'u')
			return (ft_print_num_base(DEC_DIGS, va_arg(args, unsigned int)));
		else if (*(str + 1) == 'x')
			return (ft_print_num_base(HEXA_LO, va_arg(args, unsigned int)));
		else if (*(str + 1) == 'X')
			return (ft_print_num_base(HEX_UP, va_arg(args, unsigned int)));
		else if (*(str + 1) == '%')
			return (write(1, "%", 1));
		return (1);
	}
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		processed_length;

	i = 0;
	va_start(args, str);
	while (*str)
	{
		processed_length = ft_detect_converters((char *)str, args);
		if (processed_length > 0 || *str == '%')
		{
			str ++;
			i += processed_length;
			processed_length = 0;
		}
		else
		{
			write(1, str, 1);
			i ++;
		}
		str ++;
	}
	va_end(args);
	return (i);
}
