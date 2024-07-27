/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:47:59 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/27 04:47:42 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	upon_press(mlx_key_data_t keydata, void* param);
void	upon_scroll(double xdelta, double ydelta, void* param);
void	upon_close(void* param);

void	upon_press(mlx_key_data_t keydata, void* param)
{
	t_fractal	*fr;

	fr = (t_fractal *)param;
	
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fr->move_ver += (0.25 * fr->zoom);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fr->move_ver -= (0.25 * fr->zoom);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fr->move_hor -= (0.25 * fr->zoom);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fr->move_hor += (0.25 * fr->zoom);
	else if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		fr->iter_rendition += 5;
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		fr->iter_rendition -= 5;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		upon_close(fr);
	draw_fractal(fr);
}

void	upon_scroll(double xdelta, double ydelta, void* param)
{
	t_fractal	*fr;

	fr = (t_fractal *)param;
	(void)xdelta;
	if (ydelta > 0)
		fr->zoom *= 1.1;
	else if (ydelta < 0)
		fr->zoom /= 1.1;
	draw_fractal(fr);
}

void	upon_close(void* param)
{
	t_fractal	*fr;

	fr = (t_fractal *)param;
	frexit(NULL, fr, EXIT_SUCCESS);
}