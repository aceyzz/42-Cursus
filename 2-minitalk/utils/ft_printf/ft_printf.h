/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:13:58 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/18 18:22:48 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ------------------------------------------------------------------------- */
/* 									Definitions								 */
/* ------------------------------------------------------------------------- */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/* ------------------------------------------------------------------------- */
/* 							Libraries std necessaires						 */
/* ------------------------------------------------------------------------- */
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
/* ------------------------------------------------------------------------- */
/* 								Fonctions seules							 */
/* ------------------------------------------------------------------------- */
int		ft_printf(const char *origin, ...);
int		ft_check(char c, va_list args, int count);
int		print_base(size_t nb, int base);
int		print_nb(long long int nb);
int		print_s(char *str);
int		print_c(char c);
int		print_base2(size_t nb, int base);
int		whatsthelen(size_t nb, int base);
size_t	whatsthelen2(long long int nb);
int		ft_atoi(const char *str);

#endif
