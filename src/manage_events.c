/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:47:59 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/28 07:38:00 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	upon_press(mlx_key_data_t keydata, void* param);
void	upon_scroll(double xdelta, double ydelta, void* param);
void	upon_close(void* param);

void	update_geometry(t_fractal *fr);
void	move_fractal(t_fractal *fr, mlx_key_data_t keydata);
void	move_bounds(t_fractal *fr, mlx_key_data_t keydata);
void	change_resolution(t_fractal *fr, mlx_key_data_t keydata);
void	zoom_in(t_fractal *fr);
void	zoom_out(t_fractal *fr);



void	update_to_new_center(t_fractal *fr);
void	update_center_to_cursor(t_fractal *fr);

void	upon_press(mlx_key_data_t keydata, void* param)
{
	t_fractal	*fr;

	fr = (t_fractal *)param;
	if ((keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS) ||
	(keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS) ||
	(keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS) ||
	(keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		move_fractal(fr, keydata);
	else if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS) ||
	(keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS) ||
	(keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS) ||
	(keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS))
		move_bounds(fr, keydata);
	else if ((keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS) ||
	(keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS))
		change_resolution(fr, keydata);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		upon_close(fr);
}

void	upon_scroll(double xdelta, double ydelta, void* param)
{
	t_fractal	*fr;
	int			cursor_x;
	int			cursor_y;

	fr = (t_fractal *)param;
	(void)xdelta;
	mlx_get_mouse_pos(fr->mlx, &cursor_x, &cursor_y);
	printf("cursor_x: %d, cursor_y: %d\n", cursor_x, cursor_y);
	printf("rbound: %f, cursor_y: %f\n", fr->rbound, fr->lbound);
	fr->cursor.rl = scale_point(cursor_x, WIDTH, fr->lbound, fr->rbound);
	fr->cursor.im = scale_point(cursor_y, HEIGHT, fr->tbound, fr->bbound);
	printf("AFTER rbound: %f, cursor_y: %f\n", fr->rbound, fr->lbound);
	printf("cursor.rl: %f, cursor.im: %f\n\n\n", fr->cursor.rl, fr->cursor.im);
	
	if (ydelta < 0)
		zoom_in(fr);
	else if (ydelta > 0)
		zoom_out(fr);
}

void	upon_close(void* param)
{
	t_fractal	*fr;

	fr = (t_fractal *)param;
	frexit(NULL, fr, EXIT_SUCCESS);
}


void	update_geometry(t_fractal *fr)
{
	fr->center.rl = (fr->rbound + fr->lbound) / 2;
	fr->center.im = (fr->tbound + fr->bbound) / 2;
	fr->plot_radius_x = (fr->rbound - fr->lbound) / 2;
	fr->plot_radius_y = (fr->tbound - fr->bbound) / 2;
	fr->offset.rl = 2 * fr->plot_radius_x * MOVE_SPEED;
	fr->offset.im = 2 * fr->plot_radius_y * MOVE_SPEED;
}

void	move_fractal(t_fractal *fr, mlx_key_data_t keydata)
{
	update_geometry(fr);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		fr->tbound += fr->offset.im;
		fr->bbound += fr->offset.im;
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		fr->tbound -= fr->offset.im;
		fr->bbound -= fr->offset.im;
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		fr->rbound += fr->offset.rl;
		fr->lbound += fr->offset.rl;
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		fr->rbound -= fr->offset.rl;
		fr->lbound -= fr->offset.rl;
	}
}

void	move_bounds(t_fractal *fr, mlx_key_data_t keydata)
{
	update_geometry(fr);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		fr->tbound -= fr->offset.im;
		fr->bbound -= fr->offset.im;
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		fr->tbound += fr->offset.im;
		fr->bbound += fr->offset.im;
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		fr->rbound -= fr->offset.rl;
		fr->lbound -= fr->offset.rl;
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		fr->rbound += fr->offset.rl;
		fr->lbound += fr->offset.rl;
	}
}

void	change_resolution(t_fractal *fr, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		fr->iter_rendition += 25;
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		fr->iter_rendition -= 25;
}

void	zoom_in(t_fractal *fr)
{
	t_zoom	zm;
	
	update_geometry(fr);
	zm.old_tl.rl = fr->cursor.rl - fr->lbound;
	zm.old_br.rl = fr->rbound - fr->cursor.rl;
	zm.old_tl.im = fr->tbound - fr->cursor.im;
	zm.old_br.im = fr->cursor.im - fr->bbound;
	zm.new_tl.rl = zm.old_tl.rl / MAGNIFICATION;
	zm.new_tl.im = zm.old_tl.im / MAGNIFICATION;
	zm.new_br.rl = zm.old_br.rl / MAGNIFICATION;
	zm.new_br.im = zm.old_br.im / MAGNIFICATION;

	fr->lbound = fr->cursor.rl - zm.new_tl.rl;
	fr->rbound = fr->cursor.rl + zm.new_br.rl;
	fr->tbound = fr->cursor.im + zm.new_tl.im;
	fr->bbound = fr->cursor.im - zm.new_br.im;
	printf("zoomed_in\n");
}

void	zoom_out(t_fractal *fr)
{
	t_zoom	zm;
	
	update_geometry(fr);
	zm.old_tl.rl = fr->cursor.rl - fr->lbound;
	zm.old_br.rl = fr->rbound - fr->cursor.rl;
	zm.old_tl.im = fr->tbound - fr->cursor.im;
	zm.old_br.im = fr->cursor.im - fr->bbound;
	zm.new_tl.rl = zm.old_tl.rl * MAGNIFICATION;
	zm.new_tl.im = zm.old_tl.im * MAGNIFICATION;
	zm.new_br.rl = zm.old_br.rl * MAGNIFICATION;
	zm.new_br.im = zm.old_br.im * MAGNIFICATION;

	fr->lbound = fr->cursor.rl - zm.new_tl.rl;
	fr->rbound = fr->cursor.rl + zm.new_br.rl;
	fr->tbound = fr->cursor.im + zm.new_tl.im;
	fr->bbound = fr->cursor.im - zm.new_br.im;
	printf("zoomed_out\n");
}










void	update_to_new_center(t_fractal *fr)
{
	fr->center.rl = (fr->rbound + fr->lbound) / 2;
	fr->center.im = (fr->tbound + fr->bbound) / 2;
	fr->plot_radius_x = (fr->rbound - fr->lbound) / 2 * fr->zoom;
	fr->plot_radius_y = (fr->tbound - fr->bbound) / 2 * fr->zoom;
}

void	update_center_to_cursor(t_fractal *fr)
{
	fr->center.rl = fr->cursor.rl;
	fr->center.im = fr->cursor.im;
}

void	update_bounds0(t_fractal *fr)
{
	// fr->lbound = (fr->center.rl - fr->plot_radius_x) * fr->zoom;
	// fr->rbound = (fr->center.rl + fr->plot_radius_x) * fr->zoom;
	// fr->tbound = (fr->center.im + fr->plot_radius_y) * fr->zoom;
	// fr->bbound = (fr->center.im - fr->plot_radius_y) * fr->zoom;
	
	fr->lbound = (fr->center.rl - fr->plot_radius_x);
	fr->rbound = (fr->center.rl + fr->plot_radius_x);
	fr->tbound = (fr->center.im + fr->plot_radius_y);
	fr->bbound = (fr->center.im - fr->plot_radius_y);
}
