/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:39:40 by cmanfred          #+#    #+#             */
/*   Updated: 2019/03/05 22:02:33 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "image.h"
#include "libft.h"
#include "mlx.h"

typedef struct	s_pthrdata
{
	int			ymax;
	int			ymin;
	t_mlx		*mlx;
}				t_pthrdata;

int		ft_pixel_color(int iter, int max, int scheme);

void    *ft_spider(void *inc);

void	*ft_mandelbrot(void *inc);

void	*ft_burning_ship(void *inc);

void	*ft_fractol_hq(void *inc);

void	*ft_comand_threads(void *inc);

t_mlx	*ft_init(char frname, void *init);

void	ft_hook(t_mlx *mlx, int *argc);

void	*ft_julia(void *mlx);

void	ft_launch_fractol(t_mlx *mlx);

#endif
