/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozbek <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:31:26 by aozbek            #+#    #+#             */
/*   Updated: 2023/08/01 12:35:28 by aozbek           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_length(int num)
{
	int	length;

	length = 0;
	if (num < 0)
		length++;
	while (num != 0)
	{
		num = (num / 10);
		length++;
	}
	return (length);
}

void	write_nbr(int num)
{
	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else if (num < 0 && num != -2147483648)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num >= 10)
	{
		write_nbr(num / 10);
		write_nbr(num % 10);
	}
	else if (num != -2147483648)
		ft_print_char(num + 48);
}

int	ft_print_nbr(int num)
{
	int	length;

	length = 0;
	if (num == -2147483648)
	{
		length = 11;
		write_nbr(num);
		return (length);
	}
	else if (num == 0)
		length++;
	else
		length = nbr_length(num);
	write_nbr(num);
	return (length);
}
