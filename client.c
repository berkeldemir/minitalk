/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:09:54 by beldemir          #+#    #+#             */
/*   Updated: 2024/12/14 21:07:55 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static pid_t	ft_strtopid(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (-1);
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	if (!(num <= 999999 && num >= 1000))
		return (-1);
	return ((pid_t)num);
}

static void ft_banner(int pid) {
	ft_printf(SETCYN);
    ft_printf(".-------------------------------.\n");
	ft_printf("|        _     _ _       _ _    |\n");
	ft_printf("|  _____|_|___|_| |_ ___| | |_  |\n");
	ft_printf("| |     | |   | |  _| .'| | '_| |\n");
	ft_printf("| |_|_|_|_|_|_|_|_| |__,|_|_,_| |\n");
	ft_printf("|___________ client ____________|\n");
	ft_printf("|                               |\n");
	ft_printf("|          by /beldemir         |\n");
	ft_printf("'-------------------------------'\n");
	ft_printf("       SELECTED PID: %d\n", pid);
	ft_printf(SETWHT);
}

static void ft_send(pid_t pid, char *msg)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	j = 0;
	while (msg[i] != \0)
	{
		bit = 7;
		while (bit >= 0)
		{
			i = (msg[i] >> pos) & 1;
			if (i == 0)
				if (kill(pid, SIGUSR1) == -1)
					return (-1);
			else
				if (kill(pid, SIGUSR2) == -1)
					return (-1);
			bit--;
			usleep(50);
		}
		i++;	
	}
	exit (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	char	*output = "heyyo";
	int		res;
	pid_t	pid;
	
	ft_banner(pid);
	if (ac != 3)
		return (ft_printf("%s%s%s", SETRED, "Invalid entry.", SETWHT), -1)
	pid = ft_strtopid(av[1]);
	if (pid == -1)
		return (ft_printf("%s%s%s\n", SETRED, "Invalid PID!",SETWHT), -1);
	if (av[2][0] == '\0')
		return (ft_printf("%s%s%s\n", SETRED, "Invalid msg.", SETWHT), -1);
	ft_printf("MESSAGE:\n%s\n", av[2]);
	res = ft_send(pid, av[2]);
	if (res == 0)
	{
		ft_printf("%s%s%s", SETGRN, "STATUS: Sent successfully.",SETWHT);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("%s%s%s", SETRED, "STATUS: A problem occured.",SETWHT);
		exit(EXIT_FAILURE);
	}
	return (0);
} 
