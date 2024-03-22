/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:22:29 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/22 19:32:11 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "printf/ft_printf.h"

void	msg_confirm(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message recieved!\n");
}

void	send_signal(pid_t server_pid, char c)
{
	int				i;
	unsigned char	b_char;

	i = 8;
	while (i > 0)
	{
		i--;
		b_char = c >> i;
		if (b_char % 2 == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		signal(SIGUSR1, msg_confirm);
		signal(SIGUSR2, msg_confirm);
		server_pid = atoi(argv[1]);
		while (argv[2][i] != '\0')
			send_signal(server_pid, argv[2][i++]);
		send_signal(server_pid, '\0');
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
//msg_confirm() func prints a message when the server receives a message