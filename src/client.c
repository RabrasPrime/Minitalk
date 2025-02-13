/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:58:22 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/13 11:30:59 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include "ft_printf.h"

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
			send_bits(process_id, argv[2][index]);
			index++;
		}
		send_bits(process_id, '\0');
	}
	else
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	return (0);
}
