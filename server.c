/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:24:56 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/26 14:57:14 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{	
	static int	bit;
	static int	i;

	if (signal == SIGUSR2)
		i |= (00000001 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
	}
	
}


int	main(int argc, char *argv[])
{
	pid_t	pid_serv;

	if (argc != 1)
	{
		printf("Wrong format");
		return (0);
	}
	pid_serv = getpid();
	printf("%d\n", pid_serv);
	printf("Waiting for a message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (1);
}