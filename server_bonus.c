/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:22:18 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/22 19:32:26 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "printf/ft_printf.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int				bit_index;
	static unsigned char	c;
	pid_t					client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= (1 << (7 - bit_index));
	bit_index++;
	if (bit_index == 8)
	{
		if (c != '\0')
			ft_printf("%c", c);
		else
		{
			ft_printf("\n");
			kill(client_pid, SIGUSR1);
		}
		bit_index = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		ft_printf("Error\n");
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("Server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
//sa_sigaction is a pointer to 'handle_signal'
//sa_flags set to SA_SIGINFO flag to receive the pid of the client
//sa_mask is init an empty signal set, so no signals are blocked
//sigaction() more flexible
//pid_t si_pid is the sending process ID