/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:24:18 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/16 23:54:39 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	setup_signal_handlers(struct sigaction *signal_action)
{
	if (sigaction(SIGUSR1, signal_action, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## Error - Could not setup SIGUSR1 ##\n\e[0m",
			STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, signal_action, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## Error - Could not setup SIGUSR2 ##\n\e[0m",
			STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	send_integer(pid_t pid, int number)
{
	int		bit_position;
	char	bit;

	bit_position = (sizeof(int) * 8) - 1;
	while (bit_position >= 0)
	{
		bit = (number >> bit_position) & 1;
		send_signal_bit(pid, bit, 1);
		bit_position--;
	}
}

void	send_character(pid_t pid, char character)
{
	int		bit_position;
	char	bit;

	bit_position = (sizeof(char) * 8) - 1;
	while (bit_position >= 0)
	{
		bit = (character >> bit_position) & 1;
		send_signal_bit(pid, bit, 1);
		bit_position--;
	}
}

void	send_signal_bit(pid_t pid, char bit, char should_pause)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_putstr_fd("\e[31m## Error - Sending SIGUSR1 ##\n\e[0m",
				STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	else if (bit == 1)
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_putstr_fd("\e[31m## Error - Sending SIGUSR2 ##\n\e[0m",
				STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	if (should_pause != 0)
		pause();
}
