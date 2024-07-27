/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 05:02:48 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/27 11:51:32 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	render_fractals(t_fractal *fr);
void	render_mandelbrot(t_fractal *fr);
void	render_julia(t_fractal *fr);

void	render_fractals(t_fractal *fr)
{
	if (fr->mode == 1)
		render_mandelbrot(fr);
	else if (fr->mode == 2)
		render_julia(fr);
	else if (fr->mode == 3)
		render_burning_ship(fr);
}

void	render_mandelbrot(t_fractal *fr)
{
	int		dim[2];
	int		escape_val;
	int		color;
	// int		offset;
	t_cmplx	tmp;

	dim[0] = 0;
	while (dim[0] < HEIGHT)
	{
		dim[1] = 0;
		while (dim[1] < WIDTH)
		{
			// tmp.rl = dim[1] * fr->zoom;
			// tmp.im = dim[0] * fr->zoom;
			tmp.rl = dim[1];
			tmp.im = dim[0];
			fr->c.rl = (scale_point(tmp.rl, WIDTH, fr->lbound, fr->rbound) * fr->zoom)  + fr->move_hor;
			fr->c.im = (scale_point(tmp.im, HEIGHT, fr->bbound, fr->tbound) * fr->zoom) + fr->move_ver;
			escape_val = blast_off(fr);
			color = scale_color(escape_val, fr->iter_rendition, RED, PSYCH_VIOLET);
			// offset = dim[0] * WIDTH + dim[1];
			mlx_put_pixel(fr->img, dim[1], dim[0], color);
			// ft_memset((fr->img->pixels + offset), color, sizeof(int));
			dim[1]++;
		}
		dim[0]++;
	}
}

void	render_julia(t_fractal *fr)
{
	int		dim[2];
	int		escape_val;
	int		color;
	t_cmplx	tmp;

	dim[0] = 0;
	while (dim[0] < HEIGHT)
	{
		dim[1] = 0;
		while (dim[1] < WIDTH)
		{
			// tmp.rl = dim[1] * fr->zoom;
			// tmp.im = dim[0] * fr->zoom;
			tmp.rl = dim[1];
			tmp.im = dim[0];
			fr->z.rl = (scale_point(tmp.rl, WIDTH, fr->lbound, fr->rbound) * fr->zoom) + fr->move_hor;
			fr->z.im = (scale_point(tmp.im, HEIGHT, fr->bbound, fr->tbound) * fr->zoom) + fr->move_ver;
			escape_val = blast_off(fr);
			color = scale_color(escape_val, fr->iter_rendition, RED, PSYCH_VIOLET);
			mlx_put_pixel(fr->img, dim[1], dim[0], color);
			dim[1]++;
		}
		dim[0]++;
	}
}

void	render_burning_ship(t_fractal *fr)
{
	int		dim[2];
	int		escape_val;
	int		color;
	t_cmplx	tmp;

	dim[0] = 0;
	while (dim[0] < HEIGHT)
	{
		dim[1] = 0;
		while (dim[1] < WIDTH)
		{
			// tmp.rl = dim[1] * fr->zoom;
			// tmp.im = dim[0] * fr->zoom;
			tmp.rl = dim[1];
			tmp.im = dim[0];
			fr->c.rl = (scale_point(tmp.rl, WIDTH, fr->lbound, fr->rbound) * fr->zoom) + fr->move_hor;
			fr->c.im = (scale_point(tmp.im, HEIGHT, fr->bbound, fr->tbound) * fr->zoom) + fr->move_ver;
			escape_val = blast_off(fr);
			color = scale_color(escape_val, fr->iter_rendition, BLACK, RED);
			mlx_put_pixel(fr->img, dim[1], dim[0], color);
			dim[1]++;
		}
		dim[0]++;
	}
}
