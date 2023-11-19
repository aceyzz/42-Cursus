/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:44:46 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/19 10:09:37 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include "../utils/ft_printf/ft_printf.h"

/* ------------------------------------------------------------------- SERVER */
void	bit_received(int sig, siginfo_t *info, void *context);
/* ------------------------------------------------------------------- CLIENT */
void	send_message(pid_t server_pid, const char *str);
void	confirmation_handler(int sig);

#endif
