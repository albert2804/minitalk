/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conv_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:56:46 by aestraic          #+#    #+#             */
/*   Updated: 2022/05/30 14:12:06 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

//converts the 8 binaries into 1 char in ascii table
void ft_conv_signal(int binary)
{
	int i;
	int ascii_code;

	i = 7;
	ascii_code = 0;
	while (i >= 0)
	{
		if (binary == 1)
			ascii_code += 2^i;
		//if (binary << i & 1)
			//ascii_code += 2^i;
		i --;	
	}
	//ft_putchar_fd(ascii_code, 1);
	ft_printf("%d", ascii_code);
}
// takes 8 binary signals from signal_function
// and writes the binaries into an array
// and converts the array in into 1 character
/*
void ft_write_signal(int a)
{
	int i;
	
	i = 0;
	while (i < 8)
	{
		if (a = 1)
			binary[i] = 1;			
		else
			binary[i] = 0;
	i ++;
	}
	ft_conv_signal(binary);
}
*/

int main(void)
{
	ft_conv_signal(1);
}
