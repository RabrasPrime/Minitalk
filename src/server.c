/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:48:18 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/13 15:27:19 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"

#define INIT_BUFFER_SIZE 128

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
	static int	bit_position = 0;
	static int	character = 0;
	static int	index = 0;
	static int	buffer_size = 0;
	static char	*buffer = NULL;

	if (!buffer)
	{
		buffer_size = INIT_BUFFER_SIZE;
		buffer = malloc(buffer_size);
		if (!buffer)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
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
	int	process_id;

	process_id = getpid();
	printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", process_id);
	printf("\033[92mWaiting for a message...\033[0m\n");

	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
