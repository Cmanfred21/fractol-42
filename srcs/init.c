/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <cmanfred@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:43:50 by cmanfred          #+#    #+#             */
/*   Updated: 2019/08/28 17:36:30 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*ft_init(char frname, void *init)
{
	t_mlx	*mlx;

	if ((mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	mlx->init = init;
	if ((mlx->window = mlx_new_window(mlx->init, WIN_WIDTH,
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
	mlx->pthreads = 1;
	mlx->name = frname;
	mlx->fractol.iter = 5000;
	mlx->fractol.color = 1;
	mlx->mass = (int *)ft_memalloc(sizeof(int) * WIN_WIDTH * WIN_HEIGHT);
	if (frname != 'j')
		mlx->mouse.flag = 1;
	return (mlx);
}
