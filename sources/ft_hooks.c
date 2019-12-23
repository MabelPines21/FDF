/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:10:47 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/23 20:16:05 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_close(void *param)
{
    (void)param;
    exit(0);
}

int     key_press(int keycode, t_fdf *fdf)
{
    if (keycode == EXIT_CODE)
        ft_close(fdf);
    return (0);
}

void     hooks(t_fdf *fdf)
{
    mlx_hook(fdf->mlx->win, 2, 0, key_press, fdf);
    mlx_hook(fdf->mlx->win, 17, 0, ft_close, fdf);
}