/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:48:18 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/11 19:02:46 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define INIT_BUFFER_SIZE 1024  

void signal_handler(int signal)
{
    static int bit_position = 0;
    static int character = 0;
    static char *buffer = NULL;
    static int index = 0;
    static int buffer_size = 0;

    if (!buffer)  // Initialisation du buffer au premier signal reçu
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
    
    bit_position++;

    if (bit_position == 8)  
    {
        if (character == '\0')  // Fin du message
        {
            write(1, buffer, index);  
            write(1, "\n", 1);
            free(buffer);  // Libération de la mémoire
            buffer = NULL; // Réinitialisation pour le prochain message
            index = 0;
            buffer_size = 0;
        }
        else 
        {
            if (index >= buffer_size - 1)  // Agrandir dynamiquement si nécessaire
            {
                buffer_size *= 2;
                char *new_buffer = realloc(buffer, buffer_size);
                if (!new_buffer)
                {
                    perror("realloc");
                    free(buffer);
                    exit(EXIT_FAILURE);
                }
                buffer = new_buffer;
            }
            buffer[index++] = character;  
        }

        bit_position = 0;
        character = 0;
    }
}

int main(void)
{
    int process_id = getpid();
    
    printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", process_id);
    printf("\033[90mWaiting for a message...\033[0m\n");

    while (1)
    {
        signal(SIGUSR1, signal_handler);
        signal(SIGUSR2, signal_handler);
        pause();
    }

    return (0);
}


