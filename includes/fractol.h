/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:39:40 by cmanfred          #+#    #+#             */
/*   Updated: 2019/03/04 15:49:30 by cmanfred         ###   ########.fr       */
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

//pthread_mutex_t lock;

void	*ft_comand_threads(void *inc);

t_mlx	*ft_init(char frname);

void	ft_hook(t_mlx *mlx);

void	*ft_julia(void *mlx);

void	ft_launch_fractol(t_mlx *mlx);

#endif
