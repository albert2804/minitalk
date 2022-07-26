/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:56:43 by aestraic          #+#    #+#             */
/*   Updated: 2022/06/08 15:57:20 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft.h>
#include <signal.h>



void signal_handler(int sig) 
{
    if (sig == SIGUSR1) 
	{
        write(1, "MESSAGE", 8);
	}
}

void ft_send_message(char *character, int pid_s)
{
	int j; 
	int i;
	
	j = 0;
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
	while(i++ < 7)
	{
		kill(pid_s, SIGUSR2);
		usleep(80);
	}
}

/*
void ft_send_message2server(char **argv, char *pid_c, int pid_s)
{
	int j; 
	int i;
	
	j = 0;
	while (argv[2][j] != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if ((argv[2][j] >> (i) & 1))
				kill(pid_s, SIGUSR1);
			else
				kill(pid_s, SIGUSR2);
			usleep(100);
			i --;
		}
	j ++;
	}
	
	i = 7;
	j = 0;
	while (pid_c[j] != '\0')
	{
		i = 7;
		while(i >= 0)
		{
			if (pid_c[j] >> i & 1)
				kill(pid_s, SIGUSR1);
			else
				kill(pid_s, SIGUSR2);
			usleep(100);
			i --;
		}
	j ++;
	}
}
*/

int main(int argc, char **argv) 
{
	char *pid_c;
	int pid_s;
	int j;


	if (argc != 3)
		return (0);
	pid_s = ft_atoi(argv[1]);
	pid_c = ft_itoa(getpid());
	ft_printf("%s", pid_c);
	j = 0;
	//if (pid == 0)

	signal(SIGUSR1, signal_handler);
	ft_send_message(argv[2], pid_s);
	//ft_send_message("", pid_s);
	ft_send_message(pid_c, pid_s);
	
	
	// while (argv[2][j] != NULL)
	// {
	// 	i = 7;
	// 	while (i >= 0)
	// 	{
	// 		if ((argv[2][j] >> (i) & 1))
	// 			kill(pid_s, SIGUSR1);
	// 		else
	// 			kill(pid_s, SIGUSR2);
	// 		usleep(100);
	// 		i--;
	// 	}
	// j++;
	// }
}
