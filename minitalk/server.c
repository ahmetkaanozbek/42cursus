/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozbek <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:06:39 by aozbek            #+#    #+#             */
/*   Updated: 2023/09/14 16:10:22 by aozbek           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reconstruct(int signum)
{
	static char	a_char;
	static int	total_bit;

	if (signum == SIGUSR2)
		a_char |= (1 << total_bit);
	total_bit++;
	if (total_bit == 8)
	{
		write(1, &a_char, 1);
		a_char = 0;
		total_bit = 0;
	}
}

int	main(void)
{
	ft_printf("The process ID of the server is: %d\n", getpid());
	signal(SIGUSR2, reconstruct);
	signal(SIGUSR1, reconstruct);
	while (1)
		pause();
	return (0);
}
