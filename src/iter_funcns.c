/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_funcns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 03:39:50 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/27 05:49:36 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_cmplx	get_next_iteration(t_cmplx z_n, t_cmplx c);
double	scale_point(double val_to_sc, double max_val, double sc_min, double sc_max);
int		scale_color(int iterations, int max_iter, int start_color, int end_color);
int		blast_off(t_fractal *fr);

t_cmplx	get_next_iteration(t_cmplx z_n, t_cmplx c)
{
	t_cmplx	z_nxt;

	z_nxt = c_add(c_pow(z_n, 2), c);
	// z_nxt = c_add(c_sqr(z_n), c);
	// z_nxt = c_sqr_plus_const(z_n, c);
	return (z_nxt);
}

// Function to scale the val_to_sc within the range sc_min and sc_max, using
// linear interpolation
double	scale_point(double val_to_sc, double max_val, double sc_min, double sc_max)
{
	double	scaled_val;
	double	ratio;

	ratio = (sc_max - sc_min) / (max_val - 0);
	scaled_val = sc_min + val_to_sc * ratio;
	return (scaled_val);
}

// Similar function as above to scale color as int
int	scale_color(int iterations, int max_iter, int start_color, int end_color)
{
	int	scaled_color;
	int	ratio;

	ratio = (end_color - start_color) / (max_iter - 0);
	scaled_color = start_color + iterations * ratio;
	return (scaled_color);
}

// Function to calculate the no. of escape_val to escape the radius
int	blast_off(t_fractal *fr)
{
	int		escape_val;
	t_cmplx	zn;

	zn = fr->z;
	escape_val = 0;
	while (escape_val < fr->iter_rendition && c_dist_sqr(zn) <= fr->bound)
	{
		zn = get_next_iteration(zn, fr->c);
		escape_val++;
	}
	return (escape_val);
}
