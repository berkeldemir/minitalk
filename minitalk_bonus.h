/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 07:42:02 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/03 11:32:54 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>

# define SETRED "\033[0;31m"
# define SETGRN "\033[0;32m"
# define SETYLW "\033[0;33m"
# define SETBLU "\033[0;34m"
# define SETCYN "\033[0;36m"
# define SETWHT "\033[0m"

# define ERRARG "Invalid argument count. Ex: ./client 195688 \"message\""
# define ERRMSG "Invalid message. Try again."
# define ERRPID "Invalid PID. Try again."
# define MSGSUCS "STATUS:\nSent successfully."
# define MSGFAIL "STATUS:\nA problem occured."

int	ft_printf(const char *str, ...);
int	ft_error(char *msg);

#endif