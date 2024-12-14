/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:09:54 by beldemir          #+#    #+#             */
/*   Updated: 2024/12/14 20:17:44 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static int	ft_strtopid(char *str)
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
	return (num);
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

int main(int ac, char **av)
{
	char	*output = "heyyo";
	
	int	pid;
	
	pid = ft_strtopid(av[1]);
	if (pid == -1)
		return (ft_printf("%s%s%s\n", SETRED, "Invalid PID!",SETWHT), -1);
	ft_banner(pid);
	
	ft_printf("\n");
	while (1)
		sleep(1);
	return (0);
} 
