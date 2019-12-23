/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:17:12 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/23 20:15:21 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// #include "../includes/fdf.h"


int		main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac !=  2)
		ft_exit(ERROR_INPUT);
	fdf = init_fdf();
	validation(av[1], fdf->map);
	fdf->mlx = init_mlx();
	renderer(fdf);
	hooks(fdf);
	mlx_loop(fdf->mlx->ptr);		
}
