/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:26:10 by aestraic          #+#    #+#             */
/*   Updated: 2023/01/04 16:08:20 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define MESSAGE "Only printable characters will be treated as a message. \
Use the client like this: ./client PID_Server (> 0) Message\n"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>
# include <signal.h>
# include <libft.h>

void	ft_send_message(char *character, int pid_s);
int		send_message_to_client(int pid_flag, int pid_c);

#endif