/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:24:56 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/31 14:01:10 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR2)
		i |= (00000001 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid_serv;

	(void)argv;
	if (argc != 1)
		return (ft_printf("Wrong format"), 1);
	pid_serv = getpid();
	ft_printf("%d\n", pid_serv);
	ft_printf("Waiting for a message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
