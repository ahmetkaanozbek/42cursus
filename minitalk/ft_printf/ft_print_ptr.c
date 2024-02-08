/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozbek <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:07:56 by aozbek            #+#    #+#             */
/*   Updated: 2023/07/31 20:32:30 by aozbek           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_length(uintptr_t ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len++;
	while (ptr != 0)
	{
		ptr = (ptr / 16);
		len++;
	}
	return (len);
}

void	write_ptr(uintptr_t new_ptr)
{
	if (new_ptr >= 16)
	{
		write_ptr(new_ptr / 16);
		write_ptr(new_ptr % 16);
	}
	else
	{
		if (new_ptr <= 9)
			ft_print_char(new_ptr + 48);
		else
			ft_print_char((new_ptr - 10) + 97);
	}
}

int	ft_print_ptr(void *ptr)
{
	uintptr_t	new_ptr;
	int			print_length;

	new_ptr = (uintptr_t)ptr;
	print_length = 0;
	print_length += write(1, "0x", 2);
	print_length += ptr_length(new_ptr);
	write_ptr(new_ptr);
	return (print_length);
}
