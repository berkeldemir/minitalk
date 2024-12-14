/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:09:06 by beldemir          #+#    #+#             */
/*   Updated: 2024/12/14 21:16:19 by beldemir         ###   ########.fr       */
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

static int bit = 7;
static int res = 0;

static void	ft_bintoascii(int signal)
{
	res = res << 1;
	if (signal == SIGUSR1)
		res = res | 1;
	bit--;
	if (bit < 0)
	{
		bit = 7;
		write(1, &res, 1);
		res = 0;
	}
}

int main(void)
{
	pid_t   pid = getpid();
	ft_banner(pid);
	
	while(1)
	{
		bit = 7;
		res = 0;
		signal(SIGUSR1, ft_bintoascii);
		signal(SIGUSR2, ft_bintoascii);
		usleep(50);
	}
	return (0);
}