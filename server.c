/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:56:46 by aestraic          #+#    #+#             */
/*   Updated: 2022/05/31 16:58:59 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <libft.h>

void signal_handler(int binary)
{
	static int i = 7;
	static int ascii_code = 0;
	static int pid_flag = 0;
	static int pid_c = 0;

	if (i == -1)
	{
		ascii_code = 0;
		i = 7;
	}
	if (binary == SIGUSR1) //transforms the binaries into asciicode
		ascii_code += 1 << i;
	
	if (pid_flag == 1 && i == 0)
	{
		pid_c = ((pid_c * 10) + ascii_code) - '0';
		//ft_printf("%d\n", pid_c);
	}
	if (i == 0 && ascii_code != 0 && pid_flag == 0)
		ft_printf("%c", ascii_code);
	else if (i == 0 && ascii_code == 0) //if 8 zeros are send this condition is true
	{									// and pid_flag is set to 1
	
	if (pid_flag == 1)					//check if pid was sent to server
	{									//if so, make pid flag to zero, so 
		//ft_printf("%d", pid_c);		// it's possible to run client.o again
		pid_flag = 0;					
		kill((pid_c + 48)/10, SIGUSR1);	// send signal to client,
		pid_c = 0;						// because the calculated pid is wrong
		usleep(80);						// by the factor times 10 - 48 bigger,
	}									// there has to be a correcting factor
	else if (pid_flag == 0)
		pid_flag = 1;
	}
	i --;		
}

int main(void)
{
	int pid_s;

	pid_s = getpid();
	ft_printf("\nPID: %d\n",pid_s);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
}
