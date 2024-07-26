/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 05:48:45 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/26 09:58:57 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_data(t_fractal *fr, char **argv);
void	init_fractal(t_fractal *fr);
void	draw_fractal(t_fractal *fr);
int		blast_off(t_fractal *fr);

void	init_data(t_fractal *fr, char **argv)
{
	fr->name = argv[1];
	fr->bound = ESC_RADIUS * ESC_RADIUS;
	fr->iter_rendition = MAX_ITER;
}

void	init_fractal(t_fractal *fr)
{
	fr->mlx = mlx_init(WIDTH, HEIGHT, fr->name, 1);
	if (!fr->mlx)
		frexit("Failed to initialize MLX", fr);
	fr->img = mlx_new_image(fr->mlx, HEIGHT, WIDTH);
	if (!fr->img)
		frexit("New image failed", fr);
	
	// Set top-half pixels to black and the bottomm-half pixels to white
	// ft_memset(fr->img->pixels, 0, fr->img->width * fr->img->height / 2 * sizeof(int32_t));
	// ft_memset((fr->img->pixels + (WIDTH * HEIGHT / 2 * sizeof(int32_t))), 255, fr->img->width * fr->img->height / 2 * sizeof(int32_t));

	draw_fractal(fr);
	
	// Display an instance of the image
	if (mlx_image_to_window(fr->mlx, fr->img, 0, 0) < 0)
		frexit("Image to window failed", fr);

	
}

void	draw_fractal(t_fractal *fr)
{
	int	i;
	int	j;
	int	iterations;
	int	color;
	// int	offset;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			fr->c.rl = scale(j, WIDTH, GRAPH_MIN, GRAPH_MAX);
			fr->c.im = scale(i, HEIGHT, GRAPH_MAX, GRAPH_MIN);
			// printf_cmplx(fr->c);
			// printf("\t");
			iterations = blast_off(fr);
			color = scale_color(iterations, fr->iter_rendition, RED, PSYCH_VIOLET);
			// offset = i * WIDTH + j;
			// printf("Iterations: %d\tColor:	%d\tOffset:	%d\n", iterations, color, offset);
			mlx_put_pixel(fr->img, j, i, color);
			// ft_memset((fr->img->pixels + offset), color, sizeof(int32_t));
			j++;
		}
		i++;
	}
}

// Function to calculate the no. of iterations to escape the radius
int	blast_off(t_fractal *fr)
{
	int		iterations;
	t_cmplx	zn;

	zn = fr->z;
	iterations = 0;
	while (iterations < fr->iter_rendition && c_dist_sqr(zn) <= fr->bound)
	{
		zn = get_next_iteration(zn, fr->c);
		iterations++;
	}
	return (iterations);
}