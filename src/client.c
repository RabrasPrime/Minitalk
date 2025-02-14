/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:58:22 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/14 16:38:55 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_minitalk.h"
#include "ft_printf.h"

volatile sig_atomic_t g_ack = 0;

void	signal_handler(int signal)
{
	(void)signal;
	g_ack = 1;
}

void	send_bits(int process_id, char character)
{
	int	bit_position;

	bit_position = 0;
	while (bit_position < 8)
	{
		g_ack = 0;
		if ((character & (0x01 << bit_position)) != 0)
			kill(process_id, SIGUSR1);
		else
			kill(process_id, SIGUSR2);
		while (!g_ack)
			pause();
		bit_position++;
	}
}

int	main(int argc, char **argv)
{
	int					process_id;
	int					index;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);

	process_id = ft_atoi(argv[1]);
	index = 0;
	while (argv[2][index] != '\0')
	{
		send_bits(process_id, argv[2][index]);
		index++;
	}
	send_bits(process_id, '\0');
	return (0);
}
