/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:56:07 by ahusic            #+#    #+#             */
/*   Updated: 2024/04/18 16:41:39 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

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
		ft_printf("Erroorrr\n");
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
