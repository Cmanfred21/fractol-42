/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:39:48 by cmanfred          #+#    #+#             */
/*   Updated: 2019/03/04 20:24:03 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <math.h>

int		ft_mouse_down(int but, int x, int y, t_mlx *mlx)
{
	//	x = 0;
	//	y = 0;
	if (but == 4)
	{
		mlx->cam.offsetx += (double)((x - WIN_WIDTH / 2 + mlx->cam.offsetx) * 0.1f);
		mlx->cam.offsety += (double)((y - WIN_HEIGHT / 2 + mlx->cam.offsety) * 0.1f);
		mlx->cam.scale *= 1.1f;
	}
	if (but == 5)
	{
		mlx->cam.offsetx -= (double)((x - WIN_WIDTH / 2 + mlx->cam.offsetx) * 0.1f);
		mlx->cam.offsety -= (double)((y - WIN_HEIGHT / 2 + mlx->cam.offsety) * 0.1f);
		mlx->cam.scale *= 0.9f;
	}
	ft_launch_fractol(mlx);
	mlx->mouse.down |= (1 << but);
	return (0);
}

static int	hook_keydown(int key, t_mlx *mlx)
{
	if (key == 49)
		mlx->mouse.flag++;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 12)
	{
		mlx->fractol.iter++;
		ft_launch_fractol(mlx);
	}
	if (key == 14)
	{
		mlx->fractol.iter--;
		ft_launch_fractol(mlx);
	}
	if (key == 6)
		mlx->pthreads += 5;
	if (key == 7)
		mlx->pthreads -=5;
	return (0);
}

static int		ft_mouse_up(int but, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	mlx->mouse.down &= ~(1 << but);
	return (0);
}

static int	ft_mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->mouse.prevx == 0)
		mlx->mouse.prevx = x;
	if (mlx->mouse.prevy == 0)
		mlx->mouse.prevy = y;
	mlx->mouse.prevx = mlx->mouse.x;
	mlx->mouse.prevy = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (!(mlx->mouse.flag))
	{
		mlx->fractol.c_re += (x - mlx->mouse.prevx) / 5000.f;
		mlx->fractol.c_im += (y - mlx->mouse.prevy) / 5000.f;
	}
	else if (mlx->mouse.down & (1 << 1))
	{
		mlx->cam.offsetx -= (x - mlx->mouse.prevx);
		mlx->cam.offsety -= (y - mlx->mouse.prevy);
	}
	ft_launch_fractol(mlx);
	return (0);
}

void		ft_hook(t_mlx *mlx)
{
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_hook(mlx->window, 4, 0, ft_mouse_down, mlx);
	mlx_hook(mlx->window, 5, 0, ft_mouse_up, mlx);
	mlx_hook(mlx->window, 6, 0, ft_mouse_move, mlx);
}
