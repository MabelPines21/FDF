/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:39:39 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/23 20:06:19 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*init_mlx(void)
{
	t_mlx *mlx;

	mlx = (t_mlx *)ft_safe_malloc(sizeof(t_mlx));
	if (!(mlx->ptr = mlx_init()))
		ft_exit(ERROR_MLX);
	if (!(mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "FDF")))
		ft_exit(ERROR_MLX);
	if (!(mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT)))
		ft_exit(ERROR_MLX);
	if (!(mlx->data = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size, &mlx->end)))
		ft_exit(ERROR_MLX);
	return (mlx);
}

void	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_safe_malloc(sizeof(t_fdf));
	fdf->map = (t_map *)ft_safe_malloc(sizeof(t_map));
	fdf->map->color = RED;
	return (fdf);
}
