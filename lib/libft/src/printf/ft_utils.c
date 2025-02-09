/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:03:37 by tjooris           #+#    #+#             */
/*   Updated: 2024/12/03 14:14:04 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_function_table(t_f *functions)
{
	functions[0] = ft_char;
	functions[1] = ft_str;
	functions[2] = ft_pointeur;
	functions[3] = ft_int;
	functions[4] = ft_int;
	functions[5] = ft_unsigned;
	functions[6] = ft_hexamin;
	functions[7] = ft_hexamaj;
}
