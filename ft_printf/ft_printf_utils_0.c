/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parameter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:24:46 by beldemir          #+#    #+#             */
/*   Updated: 2024/11/04 19:08:06 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_flag(const char c)
{
	if (c == '#')
		return (1);
	if (c == ' ')
		return (2);
	if (c == '+')
		return (3);
	else
		return (0);
}

int	ft_check_parameter(const char c, va_list *args, int flag)
{
	if (c == '%')
		return (ft_print_c('%'));
	if (c == 'c')
		return (ft_print_c(va_arg(*args, int)));
	if (c == 'i' || c == 'd')
		return (ft_print_i_d(va_arg(*args, int), flag));
	if (c == 'p')
		return (ft_print_p(va_arg(*args, void *)));
	if (c == 'x' || c == 'X')
		return (ft_print_x(va_arg(*args, unsigned int), c, flag));
	if (c == 'u')
		return (ft_print_u(va_arg(*args, unsigned int)));
	if (c == 's')
		return (ft_print_s(va_arg(*args, char *)));
	return (0);
}
