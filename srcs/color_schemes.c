/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:13:12 by cmanfred          #+#    #+#             */
/*   Updated: 2019/03/05 21:22:06 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (255 << (s1 * 8) | (int)(255 * (iter - max / 2 + 1) / (max / 2)) << (s2 * 8) |
				(int)(255 * ((iter - max / 2 + 1) / (max / 2))) << (s3 * 8));
	return (0);
}
