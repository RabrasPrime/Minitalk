/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:48:18 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/09 23:58:01 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void signal_handler(int signal)
{
	static int bit_position;
	static int character;

	if (signal == SIGUSR1)
		character |= (0x01 << bit_position);
	bit_position++;
	if (bit_position == 8)
	{
		ft_printf("%c", character);
		bit_position = 0;
		character = 0;
	}
}

int main(int argc, char **argv)
{
	int process_id;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./server\033[0m\n");
		return (0);
	}
	process_id = getpid();
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", process_id);
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	while (argc == 1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
