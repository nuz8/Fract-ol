/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:36:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/26 06:34:58 by pamatya          ###   ########.fr       */
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

# define MAX_ITER 4
# define ESC_RADIUS 2
# define HEIGHT 800
# define WIDTH 800
# define ZOOM_FACTOR 2
# define MOVE_FACTOR 0.1

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

// errors.c
void	arg_error(int ec);

// complex_arithmetic.c
t_cmplx	c_add(t_cmplx z1, t_cmplx z2);
t_cmplx	c_sub(t_cmplx z1, t_cmplx z2);
t_cmplx	c_mult(t_cmplx z1, t_cmplx z2);
t_cmplx c_pow(t_cmplx z, int exp);
t_cmplx c_sqr(t_cmplx z);
t_cmplx c_sqr_plus_c(t_cmplx z, t_cmplx c);
double	c_distance(t_cmplx z);

// iter_funcns.c
t_cmplx	get_next_iter(t_cmplx z_n, t_cmplx c);

// utils.c
void	frexit(char *str, t_fractal *fr, int ec);

void	printf_float(char *label, double num);
void	printf_cmplx(t_cmplx z);

#endif
