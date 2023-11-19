/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:03:51 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/04 09:23:14 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}
