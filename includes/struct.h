/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:44:14 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/23 20:05:28 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "fdf.h"

typedef struct  s_map
{
	int			**arr;
	int			height;
	int			width;
	int			color;
}               t_map;

typedef struct  s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			size;
	int			end;
}               t_mlx;

typedef struct  s_fdf
{
	t_mlx		*mlx;
	t_map		*map;
}               t_fdf;

#endif
