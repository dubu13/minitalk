/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:14:13 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/20 15:25:01 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/inc/libft.h"

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
		usleep(42);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	i = 0;
	if (argc == 3 && argv[2][0] != '\0')
	{
		server_pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
			send_signal(server_pid, argv[2][i++]);
		send_signal(server_pid, '\0');
	}
}
