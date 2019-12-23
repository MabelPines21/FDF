/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:50:30 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/23 18:40:33 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/fdf.h"
#include "fdf.h"

void	*ft_safe_malloc(size_t size)
{
	void *mem;

	if (size == 0)
		return (NULL);
	if (!(mem = (void *)malloc(sizeof(void) * size)))
		ft_exit(ERROR_MALLOC);
	return (mem);
}
