/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 05:48:45 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/27 04:35:42 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_data(t_fractal *fr, char **argv);
void	init_fractal(t_fractal *fr);
void	draw_fractal(t_fractal *fr);
int		blast_off(t_fractal *fr);
void	init_events(t_fractal *fr);

void	init_data(t_fractal *fr, char **argv)
{
	fr->name = argv[1];
	fr->bound = ESC_RADIUS * ESC_RADIUS;
	fr->iter_rendition = MAX_ITER;
	fr->move_hor = 0;
	fr->move_ver = 0;
	fr->zoom = 1;
}

void	init_fractal(t_fractal *fr)
{
	fr->mlx = mlx_init(WIDTH, HEIGHT, fr->name, 0);
	if (!fr->mlx)
		frexit("Failed to initialize MLX", fr, EXIT_FAILURE);
	fr->img = mlx_new_image(fr->mlx, HEIGHT, WIDTH);
	if (!fr->img)
		frexit("New image failed", fr, EXIT_FAILURE);
	
	// Set top-half pixels to black and the bottomm-half pixels to white
	// ft_memset(fr->img->pixels, 0, fr->img->width * fr->img->height / 2 * sizeof(int32_t));
	// ft_memset((fr->img->pixels + (WIDTH * HEIGHT / 2 * sizeof(int32_t))), 255, fr->img->width * fr->img->height / 2 * sizeof(int32_t));

	draw_fractal(fr);
	// Display an instance of the image
	if (mlx_image_to_window(fr->mlx, fr->img, 0, 0) < 0)
		frexit("Image to window failed", fr, EXIT_FAILURE);
}

/*
	typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);
	void mlx_scroll_hook(mlx_t* mlx, mlx_scrollfunc func, void* param);
	
	typedef void (*mlx_closefunc)(void* param);
	void mlx_close_hook(mlx_t* mlx, mlx_closefunc func, void* param);
	
	typedef void (*mlx_keyfunc)(mlx_key_data_t keydata, void* param);
	void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);
*/

void	init_events(t_fractal *fr)
{
	mlx_key_hook(fr->mlx, &upon_press, fr);
	mlx_scroll_hook(fr->mlx, &upon_scroll, fr);
	mlx_close_hook(fr->mlx, &upon_close, fr);
}

void	draw_fractal(t_fractal *fr)
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
			tmp.rl = (dim[1] + fr->move_hor) * fr->zoom;
			tmp.im = (dim[0] + fr->move_hor) * fr->zoom;
			fr->c.rl = scale(tmp.rl, WIDTH, GRAPH_MIN, GRAPH_MAX);
			fr->c.im = scale(tmp.im, HEIGHT, GRAPH_MAX, GRAPH_MIN);
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
