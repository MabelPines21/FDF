/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:44:00 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/23 20:29:44 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

# include "fdf.h"

/*
**  ft_draw.c
*/
void    renderer(t_fdf *fdf);

/*
**  ft_exit.c
*/
void	ft_exit(char *str);

/*
**  ft_free.c
*/
void		ft_destroy_string_arr(char **arr);

/*
**  ft_hooks.c
*/
void     hooks(t_fdf *fdf);

/*
**  init.c
*/
void	*init_mlx(void);
void	*init_fdf(void);


/*
**  ft_main.c
*/
int     main(int argv, char **argc);

/*
**  ft_safe_malloc.c
*/
void	*ft_safe_malloc(size_t size);

/*
**  ft_validation.c
*/
void	validation(char *file, t_map *map);

#endif

