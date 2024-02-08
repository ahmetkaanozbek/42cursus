/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozbek <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:15:11 by aozbek            #+#    #+#             */
/*   Updated: 2023/08/01 10:47:50 by aozbek           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_length(unsigned int num)
{
	int	length;

	length = 0;
	while (num != 0)
	{
		num = (num / 16);
		length++;
	}
	return (length);
}

void	write_hex(unsigned int num, char format)
{
	if (num >= 16)
	{
		write_hex((num / 16), format);
		write_hex((num % 16), format);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + 48);
		else
		{
			if (format == 'x')
				ft_print_char((num - 10) + 97);
			else if (format == 'X')
				ft_print_char((num - 10) + 65);
		}
	}
}

int	ft_print_hex(unsigned int num, char format)
{
	int	length;

	length = 0;
	if (num == 0)
		length++;
	else
		length = hex_length(num);
	write_hex(num, format);
	return (length);
}
