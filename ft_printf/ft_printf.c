/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:54:32 by beldemir          #+#    #+#             */
/*   Updated: 2024/11/07 16:53:55 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_while(const char *str, va_list *args, int count, int flag)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			flag = ft_check_flag(*str);
			if (flag != 0)
				str++;
			while ((*str == ' ' || *str == '+') || (*str >= '0' && *str <= '9'))
			{
				if (*str++ == '+')
					flag = 3;
			}
			count += ft_check_parameter(*str, args, flag);
		}
		else
			count += ft_print_c(*str);
		str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		flag;

	va_start(args, str);
	flag = 0;
	count = 0;
	count += ft_printf_while(str, &args, count, flag);
	va_end(args);
	return (count);
}
