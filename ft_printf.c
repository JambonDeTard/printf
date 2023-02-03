/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillard <avillard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:24:21 by avillard          #+#    #+#             */
/*   Updated: 2023/02/03 10:24:21 by avillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checking(char format)
{
	char	*format_f;
	int		i;

	i = 0;
	format_f = "cspdiuxX%";
	while (format_f[i])
	{
		if (format == format_f[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_and_do(char format, va_list *args)
{
	int	len;

	len = 0;
	if (format == 's')
		len += ft_putstr_1(va_arg(*args, char *));
	if (format == 'd' || format == 'i')
		len += ft_putnbr_1(va_arg(*args, int));
	if (format == 'c')
		len += ft_putchar_1(va_arg(*args, int));
	if (format == 'x')
		len += ft_hexdecimal(va_arg(*args, int));
	if (format == 'X')
		len += ft_hedecimal(va_arg(*args, int));
	if (format == 'u')
		len += ft_unsigned(va_arg(*args, int));
	if (format == 'p')
		len += ft_pointer(va_arg(*args, void *));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		len;

	count = 0;
	len = 0;
	va_start (args, format);
	while (format[count])
	{
		if (format[count] == '%' && ft_checking(format[count + 1]) == 1)
		{
			if (format[count + 1] == '%')
				len += ft_putchar_1('%');
			else
				len += ft_check_and_do(format[count + 1], &args);
			count++;
		}
		else
			len += ft_putchar_1(format[count]);
		count++;
	}
	va_end (args);
	return (len);
}