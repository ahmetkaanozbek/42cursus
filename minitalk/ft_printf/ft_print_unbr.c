/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozbek <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:17:18 by aozbek            #+#    #+#             */
/*   Updated: 2023/08/01 15:29:45 by aozbek           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unbr_length(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	while (num != 0)
	{
		num = (num / 10);
		len++;
	}
	return (len);
}

void	write_unbr(unsigned int num)
{
	if (num > 9)
	{
		write_unbr(num / 10);
		write_unbr(num % 10);
	}
	else
		ft_print_char(num + 48);
}

int	ft_print_unbr(unsigned int num)
{
	int	length;

	write_unbr(num);
	length = unbr_length(num);
	return (length);
}
