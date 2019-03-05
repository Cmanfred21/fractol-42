/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:43:16 by cmanfred          #+#    #+#             */
/*   Updated: 2019/03/05 20:51:32 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "libft.h"
# include "mlx.h"

# define WIN_WIDTH 854
# define WIN_HEIGHT 480

typedef struct	s_image
{
	void		*ptr;
	char		*data;
	int			bitspp;
	int			string;
	int			endian;
}				t_image;

typedef struct	s_cam
{
	double		offsetx;
	double		offsety;
	double		scale;
	int			zoomx;
	int			zoomy;
}				t_cam;

typedef struct	s_mouse
{
	int			x;
	int			y;
	int			prevx;
	int			prevy;
	int			down;
	int			flag;
}				t_mouse;

typedef	struct	s_fractol
{
	double		c_im;
	double		c_re;
	double		old_re;
	double		old_im;
	double		new_re;
	double		new_im;
	int			iter;
	int			color;
}				t_fractol;
	

typedef struct	s_mlx
{
	void		*init;
	void		*window;
	t_image		*image;
	t_cam		cam;
	t_mouse		mouse;
	t_fractol	fractol;
	int			pthreads;
	int			ymin;
	int			ymax;
	char		name;
}				t_mlx;

t_image			*ft_delimage(t_mlx *mlx, t_image *img);

void			ft_image_set_pixel(t_image *image, int x, int y, int color);

t_image			*ft_new_image(t_mlx *mlx);

#endif
