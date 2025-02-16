/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:58:22 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/16 23:40:53 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("\e[33m > ACK signal received from server\n\e[0m",
			STDOUT_FILENO);
	else if (signal == SIGUSR2)
	{
		ft_putstr_fd("\e[92m > End of message signal received from server\n\e[0m",
			STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

static void	send_message_to_server(int server_pid, char *message)
{
	int	index;

	index = 0;
	{
		ft_putstr_fd("\e[92mSending length = [", STDOUT_FILENO);
		ft_putnbr_fd(ft_strlen(message), STDOUT_FILENO);
		ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
		send_int(server_pid, ft_strlen(message));
		ft_putstr_fd("\e[92mSending message\n\e[0m", STDOUT_FILENO);
		while (message[index] != '\0')
			send_char(server_pid, message[index++]);
		ft_putstr_fd("\e[92mSending null string terminator\n\e[0m", STDOUT_FILENO);
		send_char(server_pid, '\0');
	}
}

int	main(int argc, char **argv)
{	
	struct sigaction	client_signal;

	if (argc != 3)
	{
		ft_putstr_fd("\e[31m## Error - Incorrect syntax ##\n\e[0m", STDOUT_FILENO);
		ft_putstr_fd(
			"\e[92m./client <server PID> <message to send>\n\e[0m",
			STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	else if (kill(ft_atoi(argv[1]), 0) < 0)
	{
		ft_putstr_fd("\e[31m## Error - Invalid PID ##\n\e[0m", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	sigemptyset(&client_signal.sa_mask);
	client_signal.sa_flags = SA_RESTART;
	client_signal.sa_handler = signal_handler;
	configure_sigaction_signals(&client_signal);
	ft_putstr_fd("\e[92mClient [PID = ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
	send_message_to_server(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}

