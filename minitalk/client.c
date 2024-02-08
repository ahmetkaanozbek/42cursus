/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozbek <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:11:27 by aozbek            #+#    #+#             */
/*   Updated: 2023/09/14 16:16:52 by aozbek           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (nptr[i] - '0') + (res * 10);
		i++;
	}
	return (res * sign);
}

void	bit_sender(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (j < 8)
		{
			if ((str[i] >> j) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j++;
			usleep(150);
		}
		j = 0;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc > 3)
	{
		ft_printf("Too many arguments. You can only have two arguments.\n");
		exit(EXIT_FAILURE);
	}
	else if (argc < 3)
	{
		ft_printf("Too few arguments. You need to have two arguments.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (!pid || pid < 0)
		{
			ft_printf("Pid value is not valid.\n");
			exit(EXIT_FAILURE);
		}
		bit_sender(pid, argv[2]);
	}
	return (0);
}
