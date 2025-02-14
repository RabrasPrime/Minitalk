/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:10:56 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/14 16:28:34 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"



static void	handle_character(char **buffer, int *index,
	int *buffer_size, int character)
{
	if (character == '\0')
	{
		write(1, *buffer, *index);
		write(1, "\n", 1);
		free(*buffer);
		*buffer = NULL;
		*index = 0;
		*buffer_size = 0;
		return ;
	}
	if (*index >= *buffer_size - 1)
	{
		*buffer_size *= 2;
		char *new_buffer = ft_realloc(*buffer, *buffer_size);
		if (!new_buffer)
		{
			free(*buffer);
			ft_error();
		}
		*buffer = new_buffer;
	}
	(*buffer)[(*index)++] = character;
}

void	signal_handler(int signal)
{
	static int	bit_position;
	static int	character;
	static int	index;
	static int	buffer_size;
	static char	*buffer;

	if (!buffer)
	{
		buffer_size = INIT_BUFFER_SIZE;
		buffer = malloc(buffer_size);
		if (!buffer)
			ft_error();
	}
	if (signal == SIGUSR1)
		character |= (0x01 << bit_position);
	if (++bit_position == 8)
	{
		handle_character(&buffer, &index, &buffer_size, character);
		bit_position = 0;
		character = 0;
	}
}

int	main(void)
{
	int process_id;
	struct sigaction sa_usr1;
	struct sigaction sa_usr2;

	process_id = getpid();
	printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", process_id);
	printf("\033[92mWaiting for a message...\033[0m\n");

	sa_usr1.sa_handler = signal_handler;
	sa_usr1.sa_flags = 0;
	sigemptyset(&sa_usr1.sa_mask);
	if (sigaction(SIGUSR1, &sa_usr1, NULL) == -1)
		ft_error()
	sa_usr2.sa_handler = signal_handler;
	sa_usr2.sa_flags = 0;
	sigemptyset(&sa_usr2.sa_mask);
	if (sigaction(SIGUSR2, &sa_usr2, NULL) == -1)
		ft_error();

	while (1)
	{
		pause();
	}

	return (0);
}
