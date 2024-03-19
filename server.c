/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:14:15 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/19 21:09:19 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/inc/libft.h"

void	handle_signal(int signal)
{
	static int	bit;
	static char	c;

	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		ft_printf("Server PID: %d\n", getpid());
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
	}
}
