/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:09:06 by beldemir          #+#    #+#             */
/*   Updated: 2024/12/24 13:42:27 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int bit = 7;

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

static void	ft_receive(int signal)
{
	static unsigned char	x;
	static int				i;

	if (signal == SIGUSR1)
		x = x | 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", x);
		i = 0;
		x = 0;
	}
	x = x << 1;
}

int main(void)
{
	pid_t   pid;
	
	pid = getpid();
	ft_banner(pid);
	signal (SIGUSR1, ft_receive);
	signal (SIGUSR2, ft_receive);
	while (1)
		pause();
	return (0);
}