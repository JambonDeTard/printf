/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillard <avillard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:53:53 by avillard          #+#    #+#             */
/*   Updated: 2023/02/03 10:53:53 by avillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//mettre putstr_1
int	ft_putstr_1(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putchar_1(char c)
{
	write(1, &c, 1);
	return (1);
}

//mettre putnbr_1
int	ft_putnbr_1(int nbr)
{
	int	i;

	i = 0;	
	if (nbr == -2147483648)
	{
		i += ft_putchar_1('-');
		i += ft_putchar_1('2');
		i += ft_putnbr_1(147483648);
	}
	else if (nbr < 0)
	{
		i += ft_putchar_1('-');
		i += ft_putnbr_1(nbr * -1);
	}
	if (nbr < 10)
		i += ft_putchar_1(nbr + '0');
	else
	{
		i += ft_putnbr_1(nbr / 10);
		i += ft_putnbr_1(nbr % 10);
	}
	return (i);
}

int	ft_hexdecimal(unsigned int nbr)
{
	unsigned int	len;

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
		len += ft_hexdecimal(nbr / 16);
		len += ft_hexdecimal(nbr % 16);
	}
	return (len);
}

int	ft_hedecimal(unsigned int nbr)
{
	unsigned int	len;

	len = 0;
	if (nbr < 16)
	{
		if (nbr < 10)
			len += ft_putchar_1(nbr + 48);
		else
			len += ft_putchar_1(nbr + 55);
	}
	if (nbr > 15)
	{
		len += ft_hedecimal(nbr / 16);
		len += ft_hedecimal(nbr % 16);
	}
	return (len);
}