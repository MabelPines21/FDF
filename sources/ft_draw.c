/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:43:43 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/23 20:09:54 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_pixel(int x, int y, int color, int *data)
{
	data[x + y * WIDTH] = color;
}

void        renderer(t_fdf *fdf)
{
	int		x;
	int		y;

	x = -1;
	while (++x < fdf->map->width)
	{
		y = -1;
		while (++y < fdf->map->height)
		{
			ft_put_pixel(x * 50, y * 50, fdf->map->color, fdf->mlx->data);
		}
	}
	
	mlx_put_image_to_window(fdf->mlx->ptr, fdf->mlx->win, fdf->mlx->img, 0, 0);
}
