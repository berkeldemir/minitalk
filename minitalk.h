/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 07:42:02 by beldemir          #+#    #+#             */
/*   Updated: 2024/12/12 20:43:46 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdarg.h>

# define SETRED "\033[0;31m"
# define SETGRN "\033[0;32m"
# define SETYLW "\033[0;33m"
# define SETWHT "\033[0m"

int	ft_printf(const char *str, ...);


#endif