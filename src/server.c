/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:48:18 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/16 23:40:52 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	check_if_message_finished(
	t_protocol *server, int *index, pid_t client_pid)
{
	if (server->bit_count == 8 && server->is_receiving_message)
	{
		server->message[*index] = server->data;
		(*index)++;
		if (server->data == '\0')
		{
			ft_putstr_fd("\e[92mReceived message: [", STDOUT_FILENO);
			ft_putstr_fd(server->message, STDOUT_FILENO);
			ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
			free(server->message);
			server->message = NULL;
			server->is_receiving_message = 0;
			*index = 0;
			send_bit(client_pid, 1, 0);
		}
		server->bit_count = 0;
	}
}

static void	check_if_length_received(t_protocol *server)
{
	if (server->bit_count == sizeof(int) * 8 && !server->is_receiving_message)
	{
		server->is_receiving_message = 1;
		ft_putstr_fd("\e[92mReceived length: [", STDOUT_FILENO);
		ft_putnbr_fd(server->data, STDOUT_FILENO);
		ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
		server->message = ft_calloc(server->data + 1, sizeof(char));
		if (!server->message)
		{
			ft_putstr_fd("\e[31m## Error - ft_calloc() ##\n\e[0m", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
		server->message[server->data] = '\0';
		server->bit_count = 0;
	}
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static t_protocol	server;
	static int		message_index;

	usleep(WAIT_US);
	(void)context;
	(void)info;
	if (server.bit_count == 0)
		server.data = 0;
	if (signal == SIGUSR2 && !server.is_receiving_message)
		server.data |= 1 << (((sizeof(int) * 8) - 1) - server.bit_count);
	else if (signal == SIGUSR2 && server.is_receiving_message)
		server.data |= 1 << (((sizeof(char) * 8) - 1) - server.bit_count);
	server.bit_count++;
	check_if_length_received(&server);
	check_if_message_finished(&server, &message_index, info->si_pid);
	send_bit(info->si_pid, 0, 0);
}

int	main(void)
{
	struct sigaction	signal_config;

	sigemptyset(&signal_config.sa_mask);
	signal_config.sa_sigaction = signal_handler;
	signal_config.sa_flags = SA_SIGINFO | SA_RESTART;
	configure_sigaction_signals(&signal_config);
	ft_putstr_fd("\e[92mServer [PID = ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}


