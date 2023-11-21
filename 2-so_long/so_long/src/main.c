/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:23:02 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/21 11:12:25 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	is_valid_charac(char c)
{
	if (c == 'P' || c == 'C' || c == '1' || c == '0' || c == 'x' || c == '\n')
		return (true);
	return (false);
}

bool	is_valid_string(char **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k] && is_valid_charac(map[i][k]))
			k++;
		i++;
	}
	if (!map[i])
		return (true);
	return (false);
}

bool	is_size_ok(char **map)
{
	int		i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i - 1]) != ft_strlen(map[i]))
			return (false);
		i++;
	}
	if (i < 3 || ft_strlen(map[i - 1]) < 3)
		return (false);
	else
		return (true);
}

bool	is_valid_map(char **map)
{
	if (!is_size_ok(map) || !is_finishable(map) || !is_valid_string(map))
		return (false);
	return (true);
}

char	**parse_map(int fd)
{
	char	**map;
	int		i;

	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	if (!is_valid_map(map))
	{
		perror("Error:\nMap invalide.\n");
		exit(1);
	}
	return (map);
}

char	**get_map(char *filename)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error:\nOuverture de fichier.\n");
		exit(1);
	}
	map = (char**)malloc(sizeof(char*) + 1);
	if (!map)
	{
		perror("Error:\nAllocation mémoire (map) échouée.\n");
		exit(1);
	}
	return (parse_map(fd));
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc == 2)
	{
		map = get_map(argv[1]);
	}
}
