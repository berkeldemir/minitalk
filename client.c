/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:09:54 by beldemir          #+#    #+#             */
/*   Updated: 2024/12/12 19:20:08 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int main(void)
{
	char	*output = "heyyo";
	ft_printf("%s%s%s",SETRED, output, SETWHT);
	return (0);
}
