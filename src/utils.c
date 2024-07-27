/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:28:21 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/27 02:30:29 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	frexit(char *str, t_fractal *fr, int status);

void	printf_float(char *label, double num);
void	printf_cmplx(t_cmplx z);

void	frexit(char *str, t_fractal *fr, int status)
{
	if (str)
		perror(str);
	if (fr->mlx)
		mlx_terminate(fr->mlx);
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