/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <cmanfred@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:44:58 by cmanfred          #+#    #+#             */
/*   Updated: 2019/08/15 18:43:55 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int		ft_close_window(int *argc)
{
	(*argc)--;
	if (*argc == 1)
		exit(0);
	return (0);
}

void	*ft_fractol_hq(void *inc)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)inc;
	if (mlx->name == 'j')
		ft_julia(inc);
	else if (mlx->name == 'm')
		ft_mandelbrot(inc);
	else if (mlx->name == 's')
		ft_spider(inc);
	else if (mlx->name == 'b')
		ft_burning_ship(inc);
	else if (mlx->name == 'l')
		ft_lambda(inc);
	else if (mlx->name == 'd')
		ft_drop(inc);
	else if (mlx->name == 'v')
		ft_mandelvrot(inc);
	return (NULL);
}

int		ft_color_calc(int iter, int max, int scheme)
{
	int		s1;
	int		s2;
	int		s3;

	s1 = scheme / 100;
	s2 = (scheme / 10) % 10;
	s3 = scheme % 10;
	if (iter <= max / 2)
		return ((255 / (max / 2 - iter + 1)) << (s1 * 8));
	else
		return (255 << (s1 * 8) | (int)(255 * (iter - max / 2 + 1)
					/ (max / 2)) << (s2 * 8) | (int)(255 * ((iter - max
							/ 2 + 1) / (max / 2))) << (s3 * 8));
			return (0);
}

int		ft_pixel_color(int iter, int max, int scheme)
{
	if (scheme == 18)
		return (12345678 * iter);
	else if (scheme == 19)
		return (ft_color_calc(iter, max, 12));
	else if (scheme == 20)
		return (ft_color_calc(iter, max, 120));
	else if (scheme == 21)
		return (ft_color_calc(iter, max, 210));
	else if (scheme == 23)
		return (255 * iter / max | (255 * iter / max) << 8 |
				(255 * iter / max) << 16);
	else
		return (12345678 * iter);
	return (0);
}

void	ft_move_arrows(int key, t_mlx *mlx)
{
	double	step;

	step = 10;
	if (key == 123)
		mlx->cam.offsetx += step;
	else if (key == 124)
		mlx->cam.offsetx -= step;
	else if (key == 125)
		mlx->cam.offsety -= step;
	else if (key == 126)
		mlx->cam.offsety += step;
	ft_launch_fractol(mlx);
}
