/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:09:06 by beldemir          #+#    #+#             */
/*   Updated: 2024/12/12 21:15:35 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
    pid_t   pid = getpid();
    ft_printf("%s%s%i%s\n", SETRED, "PID OF THIS SERVER: ", (int)pid, SETWHT);
    while(1)
        sleep(1);
}