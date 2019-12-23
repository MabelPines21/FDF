/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:05:52 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/23 19:36:54 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_destroy_string_arr(char **arr)
{
	int		i;

	i = -1;
	if (arr && arr[0])
	{
		while (arr[++i])
			;
		while (--i >= 0)
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		free(arr);
		arr = NULL;
	}
	else if (arr)
	{
		free(arr);
	}
}