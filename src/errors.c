/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:25:30 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/25 04:46:26 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	arg_error(int ec);

void	arg_error(int ec)
{
	ft_fprintf(2, "Usage: ./fractol <fractal_name> <opt_args>\n");
	ft_fprintf(2, "Available options:\n");
	ft_fprintf(2, "\t1. \"Mandelbrot\"\n");
	ft_fprintf(2, "\t2. \"Julia\" <real> <img>\n");
	exit(ec);
}