/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:09:06 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/02 09:53:15 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

static int bitc = 7;

static void	ft_receive(int signal)
{
	static unsigned char	ch = 0;

	if (signal == SIGUSR1)
	{
		ft_printf("SIGUSR1\n");
		ch = (ch >> 1) | 1;
	}
	if (signal == SIGUSR2)
	{
		ft_printf("SIGUSR2\n");
		ch = ch >> 1;
	}
	if (bitc == 0)
	{
		ft_printf("%c", ch);
		bitc = 7;
		ch = 0;
		return ;
	}
	bitc--;
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
