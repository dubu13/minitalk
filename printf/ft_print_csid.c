/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/10/30 22:39:04 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chr(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	unsigned int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		ft_print_chr(*str);
		str++;
		count++;
	}
	return (count);
}

int	ft_print_int(long num)
{
	char	*new;
	int		count;

	new = ft_itoa_2(num);
	count = ft_print_str(new);
	free(new);
	return (count);
}
