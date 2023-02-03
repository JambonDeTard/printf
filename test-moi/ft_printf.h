/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillard <avillard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:57:38 by avillard          #+#    #+#             */
/*   Updated: 2023/02/03 13:57:38 by avillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_unsigned(int nbr);
int		ft_pointerhexdecimal(unsigned long nbr);
int		ft_pointer(void *ptr);
int		ft_putchar_1(char c);
int		ft_putnbr_1(int nb);
int		ft_putstr_1(char *str);
int		ft_hexdecimal(unsigned int nbr);
int		ft_hedecimal(unsigned int nbr);
int		ft_checking(char format);
int		ft_check_and_do(char format, va_list *args);
int		ft_printf(const char *format, ...);
#endif