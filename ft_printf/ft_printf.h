/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:05:15 by beldemir          #+#    #+#             */
/*   Updated: 2024/11/04 19:08:47 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

# ifdef __APPLE__
#  define NULLSTRING "(null)"
#  define NULLPOINTER "0x0"
# else
#  define NULLSTRING "(null)"
#  define NULLPOINTER "(nil)"
# endif

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define HEXAUP "0123456789ABCDEF"
# define HEXADOWN "0123456789abcdef"

int	ft_print_c(int const c);
int	ft_base(unsigned long num, char *ref);
int	ft_print_s(char *s);
int	ft_print_p(void *p);
int	ft_print_i_d(int i, int flag);
int	ft_print_u(unsigned int n);
int	ft_print_x(unsigned int n, const char c, int flag);

int	ft_check_flag(const char c);
int	ft_check_parameter(const char c, va_list *args, int flag);
int	ft_printf(const char *str, ...);

#endif