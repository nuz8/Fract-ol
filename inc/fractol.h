/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:36:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/26 09:59:49 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/includes/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define _PRINT 1

# define MAX_ITER 10000
# define ESC_RADIUS 2
# define HEIGHT 1000
# define WIDTH 1000
# define ZOOM_FACTOR 2
# define MOVE_FACTOR 0.1
# define GRAPH_MIN -2
# define GRAPH_MAX 2


// Color definitions: simple RGB
#define BLACK 0x000000 // RGB for black
#define WHITE 0xFFFFFF // RGB for white
#define RED   0xFF0000 // RGB for red
#define GREEN 0x00FF00 // RGB for green
#define BLUE  0x0000FF // RGB for blue
#define YELLOW 0xFFFF00 // RGB for yellow
#define CYAN   0x00FFFF // RGB for cyan
#define MAGENTA 0xFF00FF // RGB for magenta
#define PSYCH_VIOLET 0x8B00FF // Psych_ Violet

typedef struct s_cmplx
{
	double	rl;
	double	im;
}	t_cmplx;

typedef struct s_fractal
{
	// fractal
	char	*name;
	t_cmplx	z;
	t_cmplx	c;
	t_cmplx	julia;
	
	// MLX
	mlx_t	*mlx;
	
	// Image
	mlx_image_t	*img;
	
	// Hooks
	double	bound;
	int		iter_rendition;
	
}	t_fractal;


// initiations.c
void	init_data(t_fractal *fr, char **argv);
void	init_fractal(t_fractal *fr);
void	draw_fractal(t_fractal *fr);
int		blast_off(t_fractal *fr);

// errors.c
void	arg_error(int ec);

// complex_arithmetic.c
t_cmplx	c_add(t_cmplx z1, t_cmplx z2);
t_cmplx	c_sub(t_cmplx z1, t_cmplx z2);
t_cmplx	c_mult(t_cmplx z1, t_cmplx z2);
t_cmplx c_pow(t_cmplx z, int exp);
t_cmplx c_sqr(t_cmplx z);
t_cmplx c_sqr_plus_const(t_cmplx z, t_cmplx c);
double	c_dist_sqr(t_cmplx z);

// iter_funcns.c
t_cmplx	get_next_iteration(t_cmplx z_n, t_cmplx c);
double	scale(double val_to_sc, double max_val, double sc_min, double sc_max);
int	scale_color(int iterations, int max_iter, int start_color, int end_color);

// utils.c
void	frexit(char *str, t_fractal *fr);

void	printf_float(char *label, double num);
void	printf_cmplx(t_cmplx z);

#endif
