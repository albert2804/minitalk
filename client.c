/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:56:43 by aestraic          #+#    #+#             */
/*   Updated: 2023/01/04 16:10:21 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Message received\n", 17);
	}
}

void	ft_send_message(char *character, int pid_s)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (character[j] != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if (character[j] >> (i) & 1)
				kill(pid_s, SIGUSR1);
			else
				kill(pid_s, SIGUSR2);
			usleep(80);
			i --;
		}
		j ++;
	}
	while (i++ < 7)
	{
		kill(pid_s, SIGUSR2);
		usleep(80);
	}
}

int	main(int argc, char **argv)
{
	char	*pid_c;
	int		pid_s;

	pid_s = ft_atoi(argv[1]);
	if (pid_s < 1 || !argv[2][0] || argc != 3)
	{
		ft_printf(MESSAGE);
		return (0);
	}
	pid_c = ft_itoa(getpid());
	signal(SIGUSR1, signal_handler);
	ft_send_message(argv[2], pid_s);
	ft_send_message(pid_c, pid_s);
	free(pid_c);
}
