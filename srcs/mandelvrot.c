/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelvrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <cmanfred@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:26:05 by cmanfred          #+#    #+#             */
/*   Updated: 2019/08/28 17:34:13 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "fractol.h"

void		ft_color_mandelvrot(t_mlx *mlx)
{
	int		max = 0;
	int		i = -1;
	int		s1 = 2;
	int		s2 = 1;
	int		s3 = 0;

	while (++i < WIN_HEIGHT * WIN_WIDTH)
		if (mlx->mass[i] > max)
			max = mlx->mass[i];
	max -= 150;
	int		y = -1;
	while (++y < WIN_HEIGHT)
	{
		int x = -1;
		while (++x < WIN_WIDTH)
		{
			// printf("%d\n", max);
			int res = 0xFF * mlx->mass[x + y * WIN_WIDTH] / max;
			if (res > 0)
			{
				res -= 0;
				res = res > 0xFF ? 0xFF : res;
				res = res < 0 ? 0 : res;
				int		color;
				if (res <= max / 2)
					color = ((255 / (max / 2 - res + 1)) << (s1 * 8));
				else
					color = (255 << (s1 * 8) | (int)(255 * (res - max / 2 + 1)
						/ (max / 2)) << (s2 * 8) | (int)(255 * ((res - max
							/ 2 + 1) / (max / 2))) << (s3 * 8));
				ft_image_set_pixel(mlx->image, x, y, color);
			}
			else
				ft_image_set_pixel(mlx->image, x, y, 0);
			mlx->mass[x + y * WIN_WIDTH] = 0;
		}
	}
}

static int	ft_change_num_old(t_fractol *f)
{
	f->old_re = f->new_re;
	f->old_im = f->new_im;
	f->new_re = f->old_re * f->old_re - f->old_im * f->old_im + f->c_re;
	f->new_im = 2 * f->old_re * f->old_im + f->c_im;
	if ((f->new_re * f->new_re + f->new_im * f->new_im) > 4)
		return (1);
	return (0);
}


static int	ft_change_num(t_fractol *f, t_mlx *mlx)
{
	int		x;
	int		y;

	// printf(" NE SRAL\n");
	f->old_re = f->new_re;
	f->old_im = f->new_im;
	f->new_re = f->old_re * f->old_re - f->old_im * f->old_im + f->c_re;
	f->new_im = 2 * f->old_re * f->old_im + f->c_im;
	x = (int)(f->new_re * (0.5 * mlx->cam.scale * WIN_WIDTH) / 1.5 - mlx->cam.offsetx + WIN_WIDTH / 2);
	y = (int)(f->new_im * 0.5 * mlx->cam.scale * WIN_HEIGHT) - mlx->cam.offsety + WIN_HEIGHT / 2;
	if (x < WIN_WIDTH && y < WIN_HEIGHT && x > 0 && y > 0)
	{
		// printf ("NE SRAL\n");
		mlx->mass[x + y * WIN_WIDTH] += 1;
	}
	if ((f->new_re * f->new_re + f->new_im * f->new_im) > 4)
		return (1);
	return (0);
}

static void	count_point(int x, int y, t_fractol f, t_mlx *mlx)
{
	int		i;

	i = -1;
	f.c_re = 1.5 * (x + mlx->cam.offsetx - WIN_WIDTH / 2)
		/ (0.5 * mlx->cam.scale * WIN_WIDTH);
	f.c_im = (y + mlx->cam.offsety - WIN_HEIGHT / 2)
		/ (0.5 * mlx->cam.scale * WIN_HEIGHT);
	i = -1;
	while (++i < f.iter)
		if (ft_change_num_old(&f))
			break ;
	if (i < f.iter - 1)
	{
		f.c_re = 1.5 * (x + mlx->cam.offsetx - WIN_WIDTH / 2) / (0.5 * mlx->cam.scale * WIN_WIDTH);
		f.c_im = (y + mlx->cam.offsety - WIN_HEIGHT / 2) / (0.5 * mlx->cam.scale * WIN_HEIGHT);
		f.new_im = 0;
		f.new_re = 0;
		i = -1;
		while (++i < f.iter)
			if (ft_change_num(&f, mlx))
				break ;
	}
}

void		*ft_mandelvrot(void *inc)
{
	t_fractol	f;
	int			x;
	int			y;
	t_mlx		*mlx;

	mlx = (t_mlx *)inc;
	f = mlx->fractol;
	f.new_im = 0;
	f.new_re = 0;
	y = mlx->ymin - 1;
	while (++y < mlx->ymax)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			count_point(x, y, f, mlx);
	}
	return (NULL);
}
