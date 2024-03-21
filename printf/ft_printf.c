/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/10/30 15:27:47 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *prnt, ...)
{
	va_list		arg;
	int			count;

	va_start (arg, prnt);
	count = 0;
	if (!prnt)
		return (-1);
	while (*prnt != '\0')
	{
		if (*prnt == '%')
			count += ft_check_format(*(++prnt), arg);
		else
			count += write(1, prnt, 1);
		prnt++;
	}
	va_end (arg);
	return (count);
}
