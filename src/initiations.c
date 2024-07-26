/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 05:48:45 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/26 06:45:29 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_data(t_fractal *fr, char **argv);
void	init_fractal(t_fractal *fr);

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
		frexit("Failed to initialize MLX", fr, 1);
	fr->img = mlx_new_image(fr->mlx, HEIGHT, WIDTH);
	if (!fr->img)
		frexit("New image failed", fr, 1);
	
	// Set top-half pixels to black and the bottomm-half pixels to white
	ft_memset(fr->img->pixels, 0, fr->img->width * fr->img->height / 2 * sizeof(int32_t));
	ft_memset((fr->img->pixels + (WIDTH * HEIGHT / 2 * sizeof(int32_t))), 255, fr->img->width * fr->img->height / 2 * sizeof(int32_t));

	// Display an instance of the image
	if (mlx_image_to_window(fr->mlx, fr->img, 0, 0) < 0)
		frexit("Image to window failed", fr, 1);

	
}