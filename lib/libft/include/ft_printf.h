/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:04:39 by tjooris           #+#    #+#             */
/*   Updated: 2024/12/16 11:29:44 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdarg.h"
# include "stdlib.h"
# include "unistd.h"

typedef int	(*t_f)(char *, int, va_list);

int		ft_unsigned(char *str, int i, va_list arg);
int		ft_str(char *str, int i, va_list arg);
int		ft_char(char *str, int i, va_list arg);
int		ft_printlen(va_list arg, char *str);
int		ft_printf(const char *str, ...);
int		ft_pointeur(char *str, int i, va_list arg);
int		ft_int(char *str, int i, va_list arg);
int		ft_hexamin(char	*str, int i, va_list arg);
int		ft_hexamaj(char	*str, int i, va_list arg);
void	init_function_table(t_f *functions);
int		ft_printlen(va_list arg, char *str);
int		ft_printstr(va_list arg, char *str, char *dest);
#endif
