/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:43:50 by cmanfred          #+#    #+#             */
/*   Updated: 2019/03/04 20:24:07 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*ft_init(char frname)
{
	t_mlx	*mlx;

	if ((mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->init = mlx_init()) == NULL ||
			(mlx->window = mlx_new_window(mlx->init, WIN_WIDTH,
										  WIN_HEIGHT, "fractol")) == NULL ||
			(mlx->image = ft_new_image(mlx)) == NULL)
		return (NULL);
	mlx->cam.offsetx = 0;
	mlx->cam.offsety = 0;
	mlx->cam.zoomx = 0;
	mlx->cam.zoomy = 0;
	mlx->mouse.x = 0;
	mlx->mouse.y = 0;
	mlx->cam.scale = 1;
	mlx->pthreads = 120;
	mlx->name = frname;
	mlx->fractol.iter = 24;
	return (mlx);
}
