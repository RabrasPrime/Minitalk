/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:10:56 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/16 23:54:40 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	check_if_message_complete(
	communication_protocol *server_data, int *index, pid_t client_pid)
{
	if (server_data->bit_count == 8 && server_data->status_flag == 1)
	{
		server_data->message[*index] = server_data->current_data;
		(*index)++;
		if (server_data->current_data == '\0')
		{
			ft_putstr_fd("\e[92mReceived message = [", STDOUT_FILENO);
			ft_putstr_fd(server_data->message, STDOUT_FILENO);
			ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
			free(server_data->message);
			server_data->message = NULL;
			server_data->status_flag = 0;
			*index = 0;
			send_bit(client_pid, 1, 0);
		}
		server_data->bit_count = 0;
	}
}

static void	check_if_length_received(communication_protocol *server_data)
{
	if (server_data->bit_count == sizeof(int) * 8 && server_data->status_flag == 0)
	{
		server_data->status_flag = 1;
		ft_putstr_fd("\e[92mReceived length = [", STDOUT_FILENO);
		ft_putnbr_fd(server_data->current_data, STDOUT_FILENO);
		ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
		server_data->message = ft_calloc(server_data->current_data + 1, sizeof(char));
		if (server_data->message == NULL)
		{
			ft_putstr_fd("\e[31m## Error - ft_calloc() ##\n\e[0m", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
		server_data->message[server_data->current_data] = '\0';
		server_data->bit_count = 0;
	}
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static communication_protocol	server_data;
	static int			index;

	usleep(WAIT_US);
	(void)context;
	(void)info;
	if (server_data.bit_count == 0)
		server_data.current_data = 0;
	if (signal == SIGUSR2 && server_data.status_flag == 0)
		server_data.current_data |= 1 << (((sizeof(int) * 8) - 1) - server_data.bit_count);
	else if (signal == SIGUSR2 && server_data.status_flag == 1)
		server_data.current_data |= 1 << (((sizeof(char) * 8) - 1) - server_data.bit_count);
	server_data.bit_count++;
	check_if_length_received(&server_data);
	check_if_message_complete(&server_data, &index, info->si_pid);
	send_bit(info->si_pid, 0, 0);
}

int	main(void)
{
	struct sigaction	server_action;

	sigemptyset(&server_action.sa_mask);
	server_action.sa_sigaction = signal_handler;
	server_action.sa_flags = SA_SIGINFO | SA_RESTART;
	configure_sigaction_signals(&server_action);
	ft_putstr_fd("\e[92mServer [PID = ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
