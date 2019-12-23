/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:49:53 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/23 20:01:15 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		*read_big_file(char *file_str, char *filename)
{
	int			i;
	int			fd;
	int			size;
	char		buf[5000];

	i = -1;
	if (!filename)
		return (NULL);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if ((read(fd, buf, 0)) < 0)
		return (NULL);
	if ((size = (read(fd, buf, 5000))) < 0)
		return (NULL);
	file_str = (char *)ft_safe_malloc(sizeof(char) * (size + 1));
	while (++i < size)
		file_str[i] = buf[i];
	file_str[i] = '\0';
	close(fd);
	return (file_str);
}

static int	ft_len_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}

static void	fill_line(int i, char **split_white_space, t_map *map)
{
	int		k;

	k = -1;
	map->arr[i] = (int *)ft_safe_malloc(sizeof(int) * map->width);
	while (split_white_space[++k])
		map->arr[i][k] = ft_atoi(split_white_space[k]);
}

static void	fill_matrix(char **file_split_n, t_map *map)
{
	int		i;
	int		width;
	char	**split_white_space;

	i = -1;
	while (++i < map->height)
	{
		if (!(split_white_space = ft_strsplit(file_split_n[i], ' ')))
			ft_exit(ERROR_MALLOC);

		if (i == 0)
			map->width = ft_len_arr(split_white_space);
		else
			width = ft_len_arr(split_white_space);
		if (i > 0)
			if (map->width !=  width)
				ft_exit(ERROR_INPUT);
		fill_line(i, split_white_space, map);
		ft_destroy_string_arr(split_white_space);
	}
}

void		validation(char *file, t_map *map)
{
	char	**file_split_n;
	char	*file_to_str;

	if (!(file_to_str = read_big_file(file_to_str, file)))
		ft_exit(ERROR_INPUT);
	if (!(file_split_n = ft_strsplit(file_to_str, '\n')))
		ft_exit(ERROR_INPUT);
	map->height = ft_len_arr(file_split_n);
	map->arr = (int **)ft_safe_malloc(sizeof(int *) * (map->height + 1));
	map->arr[map->height] = NULL;
	fill_matrix(file_split_n, map);
	ft_strdel(&file_to_str);
	ft_destroy_string_arr(file_split_n);

	for (size_t i = 0; i < map->height; i++)
	{
		for (size_t k = 0; k < map->width; k++)
		{
			ft_putnbr(map->arr[i][k]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
