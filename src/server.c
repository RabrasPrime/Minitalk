/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:48:18 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/14 16:38:06 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "ft_minitalk.h"
#include "libft.h"

#define INIT_BUFFER_SIZE 128

static void	handle_character(t_server_data *data)
{
	if (data->character == '\0')
	{
		write(1, data->buffer, data->index);
		write(1, "\n", 1);
		free(data->buffer);
		data->buffer = NULL;
		data->index = 0;
		data->buffer_size = 0;
		return;
	}
	if (data->index >= data->buffer_size - 1)
	{
		data->buffer_size *= 2;
		char *new_buffer = ft_realloc(data->buffer, data->buffer_size);
		if (!new_buffer)
		{
			free(data->buffer);
			ft_error();
		}
		data->buffer = new_buffer;
	}
	data->buffer[data->index++] = data->character;
}


void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static t_server_data data = {0, 0, 0, INIT_BUFFER_SIZE, NULL};

	(void)context;
	if (!data.buffer)
	{
		data.buffer = malloc(data.buffer_size);
		if (!data.buffer)
			ft_error();
	}

	if (signal == SIGUSR1)
		data.character |= (0x01 << data.bit_position);

	if (++data.bit_position == 8)
	{
		handle_character(&data);
		data.bit_position = 0;
		data.character = 0;
		if (info->si_pid)
			kill(info->si_pid, SIGUSR1);
	}
}


int	main(void)
{
	t_server_data	data;
	struct sigaction sa_usr1;
	struct sigaction sa_usr2;

	data.bit_position = 0;
	data.character = 0;
	data.index = 0;
	data.buffer_size = INIT_BUFFER_SIZE;
	data.buffer = malloc(data.buffer_size);
	if (!data.buffer)
		ft_error();

	int process_id = getpid();
	printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", process_id);
	printf("\033[92mWaiting for a message...\033[0m\n");
	sa_usr1.sa_sigaction = signal_handler;
	sa_usr1.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_usr1.sa_mask);
	if (sigaction(SIGUSR1, &sa_usr1, NULL) == -1)
		ft_error();

	sa_usr2.sa_sigaction = signal_handler;
	sa_usr2.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_usr2.sa_mask);
	if (sigaction(SIGUSR2, &sa_usr2, NULL) == -1)
		ft_error();
	while (1)
		pause();
	free(data.buffer);
	return (0);
}

