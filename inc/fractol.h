/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:36:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/28 16:03:48 by pamatya          ###   ########.fr       */
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

# define MAX_ITER 100
# define ESC_RADIUS 2
# define HEIGHT 1200
# define WIDTH 1200
# define MAGNIFICATION 1.25
# define MOVE_FACTOR 0.1
# define GRAPH_XMIN -2
# define GRAPH_XMAX 2
# define GRAPH_YMAX 2
# define GRAPH_YMIN -2
# define MOVE_SPEED 0.1

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

typedef struct s_zoom
{
	t_cmplx	old_tl;
	t_cmplx	old_br;
	t_cmplx	new_tl;
	t_cmplx	new_br;
}	t_zoom;
typedef struct s_fractal
{
	// fractal
	char	*name;
	int		mode;
	t_cmplx	z;
	t_cmplx	c;
	
	// Graph / display area (0 -> WIDTH/HEIGHT)
	t_cmplx	center;
	t_cmplx	cursor;
	t_cmplx	offset;
	double	plot_radius_x;
	double	plot_radius_y;
	double	lbound;
	double	rbound;
	double	tbound;
	double	bbound;
	
	// MLX
	mlx_t	*mlx;
	
	// Image
	mlx_image_t	*img;
	
	// Hooks
	double	bound;
	int		iter_rendition;
	double	move_hor;
	double	move_ver;
	double	zoom;
}	t_fractal;

// initiations.c
void	initialize_fields(t_fractal *fr, int argc, char **argv, int mode);
void	init_fractal(t_fractal *fr);
void	init_events(t_fractal *fr);

// renditions.c
// void	render_fractals(t_fractal *fr);
void	render_fractals(void *f);
void	render_mandelbrot(t_fractal *fr);
void	render_julia(t_fractal *fr);
void	render_burning_ship(t_fractal *fr);
void	transform_bounds(t_fractal *fr);

// manage_events.c
void	upon_press(mlx_key_data_t keydata, void* param);
void	upon_scroll(double xdelta, double ydelta, void* param);
void	upon_close(void* param);

void	update_to_new_center(t_fractal *fr);
void	update_center_to_cursor(t_fractal *fr);
void	update_bounds(t_fractal *fr);

// complex_arithmetic.c
t_cmplx	c_add(t_cmplx z1, t_cmplx z2);
t_cmplx	c_sub(t_cmplx z1, t_cmplx z2);
t_cmplx	c_mult(t_cmplx z1, t_cmplx z2);
t_cmplx c_pow(t_cmplx z, int exp);
t_cmplx c_sqr(t_cmplx z);
t_cmplx c_sqr_plus_const(t_cmplx z, t_cmplx c);
t_cmplx c_sqr_plus_const_abs(t_cmplx z, t_cmplx c);
double	c_dist_sqr(t_cmplx z);
double	ft_abs(double num);

// iter_funcns.c
t_cmplx	get_next_iteration(t_cmplx z_n, t_cmplx c);
double	scale_point(double val_to_sc, double max_val, double sc_min, double sc_max);
int		scale_color(int iterations, int max_iter, int start_color, int end_color);
int		blast_off(t_fractal *fr);

// utils.c
void	arg_error(int status);
double	ft_atod(char *str);
// void	frexit(char *str, t_fractal *fr);
void	frexit(char *str, t_fractal *fr, int status);

void	printf_float(char *label, double num);
void	printf_cmplx(t_cmplx z);

#endif
