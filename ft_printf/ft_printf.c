/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozbek <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:02:11 by aozbek            #+#    #+#             */
/*   Updated: 2023/08/01 15:42:36 by aozbek           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_checker(va_list args, char specifier)
{
	int	print_length;

	print_length = 0;
	if (specifier == 'c')
		print_length += ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		print_length += ft_print_string(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		print_length += ft_print_nbr(va_arg(args, int));
	else if (specifier == 'p')
		print_length += ft_print_ptr(va_arg(args, void *));
	else if (specifier == 'x' || specifier == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), specifier);
	else if (specifier == 'u')
		print_length += ft_print_unbr(va_arg(args, unsigned int));
	else if (specifier == '%')
		print_length += ft_print_perc();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_length;
	int		i;

	va_start(args, str);
	i = 0;
	print_length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_length += format_checker(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
