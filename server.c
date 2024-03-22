/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:15:49 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/22 19:32:19 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "printf/ft_printf.h"

void	handle_signal(int signal)
{
	static int				bit_index;
	static unsigned char	c;

	if (signal == SIGUSR1)
		c |= (1 << (7 - bit_index));
	bit_index++;
	if (bit_index == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		bit_index = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		ft_printf("Error\n");
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
//print the PID of the server process
//signal() is used to specify the signal handler
//for the signals SIGUSR1 and SIGUSR2
//'handle_signal' receives signals and converts them to chars
//pause() func make server to wait for signals