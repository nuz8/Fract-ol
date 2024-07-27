/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:47:59 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/27 12:00:50 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	upon_press(mlx_key_data_t keydata, void* param);
void	upon_scroll(double xdelta, double ydelta, void* param);
void	upon_close(void* param);

void	update_to_new_center(t_fractal *fr);
void	update_center_to_cursor(t_fractal *fr);
void	update_bounds(t_fractal *fr);

void	upon_press(mlx_key_data_t keydata, void* param)
{
	t_fractal	*fr;

	fr = (t_fractal *)param;
	
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fr->move_ver += (0.25 * fr->zoom);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fr->move_ver -= (0.25 * fr->zoom);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fr->move_hor += (0.25 * fr->zoom);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fr->move_hor -= (0.25 * fr->zoom);
	else if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		fr->iter_rendition += 5;
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		fr->iter_rendition -= 5;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		upon_close(fr);
	render_fractals(fr);
	// update_to_new_center(fr);
	// update_bounds(fr);
}

void	upon_scroll(double xdelta, double ydelta, void* param)
{
	t_fractal	*fr;
	int			cursor_x;
	int			cursor_y;

	fr = (t_fractal *)param;
	(void)xdelta;
	mlx_get_mouse_pos(fr->mlx, &cursor_x, &cursor_y);
	fr->cursor.rl = scale_point(cursor_x, WIDTH, fr->lbound, fr->rbound);
	fr->cursor.im = scale_point(cursor_y, HEIGHT, fr->tbound, fr->bbound);
	if (ydelta > 0)
		fr->zoom *= 1.1;
	else if (ydelta < 0)
		fr->zoom /= 1.1;
	update_to_new_center(fr);
	update_center_to_cursor(fr);
	update_bounds(fr);
	render_fractals(fr);
}

void	update_to_new_center(t_fractal *fr)
{
	fr->center.rl = (fr->rbound + fr->lbound) / 2;
	fr->center.im = (fr->tbound + fr->bbound) / 2;
	fr->plot_radius_x = (fr->rbound - fr->lbound) / 2;
	fr->plot_radius_y = (fr->tbound - fr->bbound) / 2;
}

void	update_center_to_cursor(t_fractal *fr)
{
	fr->center.rl = fr->cursor.rl;
	fr->center.im = fr->cursor.im;
}

void	update_bounds(t_fractal *fr)
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

void	upon_close(void* param)
{
	t_fractal	*fr;

	fr = (t_fractal *)param;
	frexit(NULL, fr, EXIT_SUCCESS);
}
