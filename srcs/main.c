/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:35:48 by cmanfred          #+#    #+#             */
/*   Updated: 2019/03/05 22:46:17 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include "fractol.h"

static void	ft_init_fractol(t_mlx *mlx)
{
	if (mlx->name == 'j')
	{
		mlx->fractol.c_im = 0.5f;
		mlx->fractol.c_re = -0.5f;
	}
	else if (mlx->name == 'm')
	{
		mlx->fractol.new_re = 0;
		mlx->fractol.new_im = 0;
		mlx->fractol.old_re = 0;
		mlx->fractol.old_im = 0;
		mlx->cam.offsetx = -250;
	}
}

void		ft_launch_fractol(t_mlx *mlx)
{
	pthread_t	*threads;
	t_mlx		*data;
	int			i;
	int			step;

	step = WIN_HEIGHT / mlx->pthreads + WIN_HEIGHT -
		WIN_HEIGHT / mlx->pthreads * mlx->pthreads;
	threads = (pthread_t *)ft_memalloc(sizeof(pthread_t) * mlx->pthreads);
	data = (t_mlx *)ft_memalloc(sizeof(t_mlx) * mlx->pthreads);
	ft_bzero(mlx->image->data, WIN_WIDTH * WIN_HEIGHT * mlx->image->bitspp);
	i = -1;
	while (++i < mlx->pthreads)
	{
		data[i] = *mlx;
		data[i].ymin = step * i;
		data[i].ymax = step * (i + 1);
		pthread_create(&(threads[i]), NULL, ft_fractol_hq, &(data[i]));
	}
	i = -1;
	while (++i < mlx->pthreads)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->image->ptr, 0, 0);
	free(threads);
	free(data);
}

static void	ft_return(char *str)
{
	ft_putendl(str);
	exit(1);
}

static int	ft_check_arg(int argc, char *argv)
{
	if (argc < 2 || (ft_strcmp(argv, "julia") &&
				ft_strcmp(argv, "mandelbrot")
				&& ft_strcmp(argv, "spider")
				&& ft_strcmp(argv, "burning_ship")))
	{
		ft_putendl("usage: ./fractol fractol_name");
		ft_putendl("available names: julia, mandelbrot");
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx	**mlx;
	void	*init;
	int		i;
	int		flag;

	i = -1;
	flag = argc;
	init = mlx_init();
	mlx = (t_mlx**)ft_memalloc(sizeof(t_mlx *) * argc);
	while (++i < argc - 1)
	{
		if (ft_check_arg(argc, argv[i + 1]))
			exit(1);
		if (!(mlx[i] = ft_init(argv[i + 1][0], init)))
			ft_return("error in memory allocation");
		ft_init_fractol(mlx[i]);
		ft_launch_fractol(mlx[i]);
		ft_hook(mlx[i], &flag);
	}
	mlx_loop(init);
	return (0);
}
