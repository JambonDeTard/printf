/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillard <avillard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:01:03 by avillard          #+#    #+#             */
/*   Updated: 2023/02/03 11:01:03 by avillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(int nbr)
{
	int				len;
	unsigned int	n;

	n = nbr;
	len = 0;
	if (n > 9)
	{
		len += ft_putnbr_1(n / 10);
		len += ft_putchar_1(n % 10 + '0');
	}
	else
		len += ft_putchar_1(n + '0');
	return (len);
}

int	ft_pointerhexdecimal(unsigned long nbr)
{
	int	len;

	len = 0;
	if (nbr < 16)
	{
		if (nbr < 10)
			len += ft_putchar_1(nbr + 48);
		else
			len += ft_putchar_1(nbr + 87);
	}
	if (nbr > 15)
	{
		len += ft_pointerhexdecimal(nbr / 16);
		len += ft_pointerhexdecimal(nbr % 16);
	}
	return (len);
}

int	ft_pointer(void *ptr)
{
	int	len;

	len = 0;
	len += ft_putstr_1("0x");
	len += ft_pointerhexdecimal((unsigned long)ptr);
	return (len);
}