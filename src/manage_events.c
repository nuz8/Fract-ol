/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:47:59 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/29 02:14:38 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	upon_press(mlx_key_data_t keydata, void *param);
void	upon_scroll(double xdelta, double ydelta, void *param);
void	upon_close(void *param);

void	upon_press(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fr;

	fr = (t_fractal *)param;
	if ((keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		move_fractal(fr, keydata);
	else if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS))
		move_bounds(fr, keydata);
	else if ((keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS))
		fr->iter_rendition += 25;
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		fr->iter_rendition -= 25;
	else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		change_color(fr);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		upon_close(fr);
}

void	upon_scroll(double xdelta, double ydelta, void *param)
{
	t_fractal	*fr;
	int			cursor_x;
	int			cursor_y;

	fr = (t_fractal *)param;
	(void)xdelta;
	mlx_get_mouse_pos(fr->mlx, &cursor_x, &cursor_y);
	fr->cursor.rl = scale_p(cursor_x, WIDTH, fr->lbound, fr->rbound);
	fr->cursor.im = scale_p(cursor_y, HEIGHT, fr->bbound, fr->tbound);
	// if (ydelta < 0)
	// 	zoom_in(fr);
	// else if (ydelta > 0)
	// 	zoom_out(fr);
	if (ydelta < 0 || ydelta > 0)
		ft_zoom(fr, ydelta);
}

void	upon_close(void *param)
{
	t_fractal	*fr;

	fr = (t_fractal *)param;
	frexit(NULL, fr, EXIT_SUCCESS);
}
