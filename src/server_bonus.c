/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:10:56 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 17:41:06 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	bit_position;
	static int	character_value;

	(void)context;
	if (signal == SIGUSR1)
		character_value |= (0x01 << bit_position);
	bit_position++;
	if (bit_position == 8)
	{
		ft_printf("%c", character_value);
		bit_position = 0;
		character_value = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	int					process_id;
	struct sigaction	signal_action;

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
	signal_action.sa_sigaction = handle_signal;
	sigemptyset(&signal_action.sa_mask);
	signal_action.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &signal_action, NULL);
		sigaction(SIGUSR2, &signal_action, NULL);
		pause();
	}
	return (0);
}
