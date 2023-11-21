/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:16:55 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/04 09:29:46 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list args, int count)
{
	if (c == 'c')
		count += print_c(va_arg(args, int));
	else if (c == 's')
		count += print_s(va_arg(args, char *));
	else if (c == 'p')
	{
		count += write(1, "0x", 2);
		count += print_base(va_arg(args, size_t), 16);
	}
	else if (c == 'd' || c == 'i')
		count += print_nb(va_arg(args, int));
	else if (c == 'u')
		count += print_base(va_arg(args, unsigned int), 10);
	else if (c == 'x')
		count += print_base(va_arg(args, unsigned int), 16);
	else if (c == 'X')
		count += print_base2(va_arg(args, unsigned int), 16);
	else if (c == '%')
		count += print_s("%");
	return (count);
}

int	ft_printf(const char *origin, ...)
{
	va_list	args;
	size_t	i;
	int		writed;

	i = 0;
	writed = 0;
	va_start(args, origin);
	while (origin[i])
	{
		if (origin[i] == '%')
			writed = ft_check(origin[++i], args, writed);
		else
		{
			write(1, &origin[i], 1);
			writed++;
		}
		i++;
	}
	va_end(args);
	return (writed);
}
