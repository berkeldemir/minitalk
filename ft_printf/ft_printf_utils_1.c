/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:15:02 by beldemir          #+#    #+#             */
/*   Updated: 2024/11/25 09:16:10 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int const c)
{
	int	count;

	count = write(1, &c, 1);
	if (count == 1)
		return (1);
	return (-1);
}

int	ft_print_s(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s == NULL)
		return (ft_print_s(NULLSTRING));
	while (s[i] != '\0')
	{
		count += ft_print_c(s[i]);
		i++;
	}
	return (count);
}

int	ft_print_i_d(int n, int flag)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
		return (ft_print_s("-2147483648"));
	if (flag == 3 && n >= 0)
		count += ft_print_c('+');
	else if (flag == 2 && n >= 0)
		count += ft_print_c(' ');
	if (n < 0)
	{
		count += ft_print_c('-');
		n *= -1;
	}
	if (n < 10)
		count += ft_print_c(n + '0');
	else
	{
		count += ft_print_i_d(n / 10, 0);
		count += ft_print_c(n % 10 + '0');
	}
	return (count);
}

int	ft_print_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_print_i_d(n / 10, 0);
		count += ft_print_i_d(n % 10, 0);
	}
	else if (n <= 9)
		count += ft_print_c(n + '0');
	if (count < 0)
		return (-1);
	return (count);
}
