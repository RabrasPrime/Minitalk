/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:48:51 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/16 23:54:38 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# define WAIT_US  100 

# include "libft.h" 
# include <unistd.h> 
# include <signal.h> 
# include <stdlib.h> 

void    setup_signal_handlers(struct sigaction *signal_action);
void    send_integer(pid_t pid, int number);
void    send_character(pid_t pid, char character);
void    send_signal_bit(pid_t pid, char bit, char should_pause);

typedef struct s_protocol
{
    int     bits;
    int     data;
    int     flag;
    char    *message;
}           t_protocol;

#endif
