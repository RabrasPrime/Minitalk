/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:12:58 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 17:44:15 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	acknowledge_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("\033[0;32mAcknowledged!\033[0;32m\n");
	else
		ft_printf("\033[0;32mAcknowledged!\033[0;32m\n");
}

void	send_bits(int process_id, char character)
{
	int	bit_position;

	bit_position = 0;
	while (bit_position < 8)
	{
		if ((character & (0x01 << bit_position)) != 0)
			kill(process_id, SIGUSR1);
		else
			kill(process_id, SIGUSR2);
		usleep(500);
		bit_position++;
	}
}

int	main(int argc, char **argv)
{
	int	process_id;
	int	index;

	index = 0;
	if (argc == 3)
	{
		process_id = ft_atoi(argv[1]);
		while (argv[2][index] != '\0')
		{
			signal(SIGUSR1, acknowledge_signal);
			signal(SIGUSR2, acknowledge_signal);
			send_bits(process_id, argv[2][index]);
			index++;
		}
		send_bits(process_id, '\n');
	}
	else
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client_bonus [PID] [MESSAGE]\033[0m\n");
		return (1);
	}
	return (0);
}
