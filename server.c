/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:56:46 by aestraic          #+#    #+#             */
/*   Updated: 2023/01/04 16:04:31 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	signal_handler(int binary)
{
	static int	i = 7;
	static int	ascii_code = 0;
	static int	pid_flag = 0;
	static int	pid_c = 0;

	if (i == -1)
	{
		ascii_code = 0;
		i = 7;
	}
	if (binary == SIGUSR1)
		ascii_code += 1 << i;
	if (pid_flag == 1 && i == 0)
		pid_c = ((pid_c * 10) + ascii_code - '0');
	if (i == 0 && ascii_code != 0 && pid_flag == 0)
		ft_printf("%c", ascii_code);
	else if (i == 0 && ascii_code == 0)
	{
		pid_flag = send_message_to_client(pid_flag, pid_c);
		if (pid_flag == 1)
			pid_c = 0;
	}
	i --;
}

/**
 check if pid was sent to server
 if so, make pid flag to zero, so 
 it's possible to run client.o again
 send signal to client,
 because the calculated pid is wrong
 by the factor times 10 - 48 bigger,
 there has to be a correcting factor
*/
int	send_message_to_client(int pid_flag, int pid_c)
{
	if (pid_flag == 1)
	{
		pid_flag = 0;
		kill ((pid_c + 48) / 10, SIGUSR1);
		pid_c = 0;
		usleep (80);
	}									
	else if (pid_flag == 0)
		pid_flag = 1;
	return (pid_flag);
}

int	main(void)
{
	int	pid_s;

	pid_s = getpid();
	ft_printf("\nPID: %d\n", pid_s);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
}
