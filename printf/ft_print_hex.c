/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/10/30 14:06:05 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_low(unsigned long n)
{
	unsigned int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_hex_low(n / 16);
	}
	if (ft_print_chr("0123456789abcdef"[n % 16]) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_print_hex_up(unsigned long n)
{
	unsigned int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_hex_up(n / 16);
	}
	if (ft_print_chr("0123456789ABCDEF"[n % 16]) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_print_pointer(unsigned long pointer)
{
	unsigned int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_print_hex_low(pointer);
	return (count);
}
