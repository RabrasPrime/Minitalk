/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:48:51 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/14 16:26:00 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include "libft.h"
# include "ft_printf.h"
# include "signal.h"

# define INIT_BUFFER_SIZE 128

typedef struct s_server_data
{
	int		bit_position;
	int		character;
	int		index;
	int		buffer_size;
	char	*buffer;
}	t_server_data;


#endif