/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:17:52 by beldemir          #+#    #+#             */
/*   Updated: 2024/12/12 20:34:49 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_print_c(char c)
{
	return (write(1, &c, 1));
}

static int	ft_print_s(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s == NULL)
		return (ft_print_s("(null)"));
	while (s[i] != '\0')
	{
		count += ft_print_c(s[i]);
		i++;
	}
	return (count);
}

static int	ft_print_i_d(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_print_s("-2147483648"));
	if (n < 0)
	{
		count += ft_print_c('-');
		n *= -1;
	}
	if (n < 10)
		count += ft_print_c(n + '0');
	else
	{
		count += ft_print_i_d(n / 10);
		count += ft_print_c(n % 10 + '0');
	}
	return (count);
}

static int	ft_check_parameter(const char c, va_list *args)
{
	if (c == 'i' || c == 'd')
		return (ft_print_i_d(va_arg(*args, int)));
	if (c == 's')
		return (ft_print_s(va_arg(*args, char *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += ft_check_parameter(*++str, &args);
		else
			count += ft_print_c(*str);
		str++;
	}
	va_end(args);
	return (count);
}
