/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:28:21 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/28 19:11:21 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <string.h>

void	arg_error(int status);
double	ft_atod(char *str);
void	frexit(char *str, t_fractal *fr, int status);

void	arg_error(int status)
{
	ft_fprintf(2, "Usage: ./fractol <fractal_name> <opt_args>\n");
	ft_fprintf(2, "Available options:\n");
	ft_fprintf(2, "\t1. \"Mandelbrot\"\n");
	ft_fprintf(2, "\t2. \"Julia\" <real> <img>\n");
	ft_fprintf(2, "\t3. \"Burning ship\"\n");
	exit(status);
}

double	ft_atod(char *str)
{
	int		sign;
	int		before_point;
	double	after_point;
	double	significant_digit;

	before_point = 0;
	sign = 1;
	after_point = 0.0;
	significant_digit = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
	|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str && *str != '.' && *str >= '0' && *str <= '9')
		before_point = before_point * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		significant_digit *= 0.1;
		after_point = after_point + ((*str++ - '0') * significant_digit);
	}
	return (sign * (before_point + after_point));
}

void	frexit(char *str, t_fractal *fr, int status)
{
	if (str)
		perror(str);
	if (fr->mlx)
		mlx_terminate(fr->mlx);
	exit(status);
}
