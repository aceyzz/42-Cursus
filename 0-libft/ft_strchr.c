/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:32:47 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:45:14 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Recherche la première occurrence du caractère 'c' dans  */
/*   la chaîne de caractères 's'.                                             */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - s : La chaîne de caractères dans laquelle effectuer la recherche    */
/*      - c : Le caractère à rechercher                                       */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un pointeur vers la première occurrence de 'c' dans 's'.            */
/*      - NULL si 'c' n'est pas trouvé dans 's'.                              */
/* *****************************************************************   by.XVI */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	if (ch == '\0')
	{
		i = ft_strlen(s);
		return ((char *)s + i++);
	}
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
