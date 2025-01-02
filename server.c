/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:09:06 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/02 11:22:59 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	ft_banner(int pid) {
	ft_printf(SETBLU);
	ft_printf(".-------------------------------.\n");
	ft_printf("|        _     _ _       _ _    |\n");
	ft_printf("|  _____|_|___|_| |_ ___| | |_  |\n");
	ft_printf("| |     | |   | |  _| .'| | '_| |\n");
	ft_printf("| |_|_|_|_|_|_|_|_| |__,|_|_,_| |\n");
	ft_printf("|____________ server ___________|\n");
	ft_printf("|                               |\n");
	ft_printf("|          by /beldemir         |\n");
	ft_printf("'-------------------------------'\n");
	ft_printf("    THIS SERVER'S PID: %d\n", pid);
	ft_printf(SETWHT);
}

static int	ch = 0x00;

static void	ft_receive(int signal)
{
	static int 	bitc = 0;

	if (signal == SIGUSR1)
		ch = (ch << 1) | 1;
	else if (signal == SIGUSR2)
		ch = ch << 1;
	bitc++;
	if (bitc == 8)
	{
		write(1, &ch, 1);
		bitc = 0;
		ch = 0;
	}
	return ;
}

int main(void)
{
	pid_t   pid;
	
	pid = getpid();
	ft_banner(pid);
	signal(SIGUSR1, ft_receive);
	signal(SIGUSR2, ft_receive);
	while (1)
		pause();
	return (0);
}
