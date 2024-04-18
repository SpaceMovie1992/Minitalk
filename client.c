/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:33:09 by ahusic            #+#    #+#             */
/*   Updated: 2024/04/18 16:39:29 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void	send_signal(pid_t server_pid, char c)
{
	int				i;
	unsigned char	temp;

	i = 8;
	while (i > 0)
	{
		i--;
		temp = c >> i;
		if (temp % 2 == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	server_pid;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		while (server_pid <= 0)
			return (1);
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
