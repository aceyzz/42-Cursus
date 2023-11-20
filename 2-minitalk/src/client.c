/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:14:03 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/20 14:26:30 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	confirmation_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("\033[1;32mMessage received successfully.\033[0m\n");
		exit(0);
	}
}

void	send_message(pid_t server_pid, const char *str)
{
	int	i;
	int	bit;
	int	k;

	i = 0;
	while (1)
	{
		k = 0;
		while (k < 8)
		{
			bit = (str[i] >> k) & 1;
			if (bit)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(100);
			k++;
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	struct sigaction	sa;
	int					timeout;

	timeout = 5000000;
	if (argc != 3)
	{
		ft_printf("\033[1;31m> Error\n\033[0m");
		ft_printf("\033[1;33mUsage: %s \033[0m", argv[0]);
		ft_printf("\033[1;33m<server_pid> <message>\n\033[0m");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	sa.sa_handler = confirmation_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	send_message(server_pid, argv[2]);
	while (timeout > 0)
	{
		pause();
		timeout -= 100;
	}
	ft_printf("Timeout, message not confirmed\n");
	return (0);
}
