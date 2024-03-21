/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/10/30 13:49:29 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	num_len(long num)
{
	long	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa_2(long num)
{
	int		len;
	char	*str;
	int		sign;

	sign = 1;
	len = num_len(num);
	str = malloc((sizeof(char)) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
		sign = -1;
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = '0' + ((num * sign) % 10);
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
