/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:28:21 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/28 15:03:17 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <string.h>

void	arg_error(int status);
double	ft_atod(char *str);
void	frexit(char *str, t_fractal *fr, int status);

void	printf_float(char *label, double num);
void	printf_cmplx(t_cmplx z);

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

// int	main(void)
// {
// 	char	*str;
// 	double	num1;
// 	int		num2;

// 	num2 = 2;
// 	str = strdup("  	 -123.456");
// 	num1 = ft_atod(str);
// 	printf("%0.4f\n", num1);
// 	num1 = num1 * num2;
// 	printf("%0.4f\n", num1);
// 	return (0);
// }

void	frexit(char *str, t_fractal *fr, int status)
{
	if (str)
		perror(str);
	if (fr->mlx)
	{
		mlx_terminate(fr->mlx);
		// printf("im done2\n");
	}
	exit(status);
}

/* ************************************************************************** */
// Prohibited functions down from here:
/* ************************************************************************** */

void	printf_float(char *label, double num)
{
	if (_PRINT)
		printf("%s:	%0.5f\t\t", label, num);
	else
		return ;
}

void	printf_cmplx(t_cmplx z)
{
	if (_PRINT)
		printf("(%0.2f) + (%0.2f)i\t", z.rl, z.im);
	else
		return ;
}