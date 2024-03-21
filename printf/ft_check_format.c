/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/10/30 22:21:41 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char specifier, va_list arg)
{
	int	count;

	count = 0;
	if (specifier == '\0')
		return (-1);
	if (specifier == 'c')
		return (ft_print_chr(va_arg(arg, int)));
	if (specifier == 's')
		return (ft_print_str(va_arg(arg, char *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(va_arg(arg, int)));
	if (specifier == 'u')
		return (ft_print_int(va_arg(arg, unsigned int)));
	if (specifier == 'p')
		return (ft_print_pointer(va_arg(arg, unsigned long)));
	if (specifier == 'x')
		return (ft_print_hex_low(va_arg(arg, unsigned int)));
	if (specifier == 'X')
		return (ft_print_hex_up(va_arg(arg, unsigned int)));
	if (specifier == '%')
		return (ft_print_chr('%'));
	return (count);
}
