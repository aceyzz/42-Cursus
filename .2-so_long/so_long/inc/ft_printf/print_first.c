/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:11:18 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/04 09:20:40 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	whatsthelen(size_t nb, int base)
{
	int	i;

	i = 1;
	while ((nb / base) > 0)
	{
		i++;
		nb /= base;
	}
	return (i);
}

size_t	whatsthelen2(long long int nb)
{
	size_t	nbr;
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		nbr = (size_t)(-nb);
		i++;
	}
	else
		nbr = (size_t)nb;
	while (nbr / 10 > 0)
	{
		i++;
		nbr /= 10;
	}
	i++;
	return (i);
}

int	print_base(size_t nb, int base)
{
	if (nb > (size_t)base - 1)
		print_base(nb / base, base);
	if (nb % base < 10)
		print_c(nb % base + '0');
	else
		print_c(nb % base + 'a' - 10);
	return (whatsthelen(nb, base));
}

int	print_base2(size_t nb, int base)
{
	if (nb > (size_t)base - 1)
		print_base2(nb / base, base);
	if (nb % base < 10)
		print_c(nb % base + '0');
	else
		print_c(nb % base + 'A' - 10);
	return (whatsthelen(nb, base));
}

int	print_nb(long long int nb)
{
	size_t	nbr;
	char	*str;

	str = "0123456789";
	if (nb < 0)
	{
		nbr = (size_t)(-nb);
		write(1, "-", 1);
	}
	else
		nbr = (size_t)nb;
	if (nbr >= 10)
	{
		print_nb(nbr / 10);
		print_nb(nbr % 10);
	}
	else
		write(1, &str[nbr], 1);
	return (whatsthelen2(nb));
}
