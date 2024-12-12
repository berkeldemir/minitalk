/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:59 by beldemir          #+#    #+#             */
/*   Updated: 2024/11/25 09:17:19 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base(unsigned long n, char *ref)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_base(n / 16, ref);
	count += ft_print_c(ref[n % 16]);
	return (count);
}

int	ft_print_p(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_print_s(NULLPOINTER));
	count = ft_print_s("0x");
	count += ft_base((unsigned long)ptr, HEXADOWN);
	return (count);
}

int	ft_print_x(unsigned int n, const char c, int flag)
{
	int	count;

	count = 0;
	if (flag == 1 && n != 0)
	{
		if (c == 'X')
			count += ft_print_s("0X");
		else if (c == 'x')
			count += ft_print_s("0x");
	}
	if (c == 'x')
		count += ft_base(n, HEXADOWN);
	else if (c == 'X')
		count += ft_base(n, HEXAUP);
	return (count);
}
