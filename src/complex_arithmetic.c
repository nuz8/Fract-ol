/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_arithmetic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:05:07 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/26 08:51:43 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_cmplx	c_add(t_cmplx z1, t_cmplx z2);
t_cmplx	c_sub(t_cmplx z1, t_cmplx z2);
t_cmplx	c_mult(t_cmplx z1, t_cmplx z2);
t_cmplx c_pow(t_cmplx z, int exp);
t_cmplx c_sqr(t_cmplx z);
t_cmplx c_sqr_plus_const(t_cmplx z, t_cmplx c);
double	c_dist_sqr(t_cmplx z);

t_cmplx	c_add(t_cmplx z1, t_cmplx z2)
{
	t_cmplx	sum;

	sum.rl = z1.rl + z2.rl;
	sum.im = z1.im + z2.im;
	return (sum);
}

t_cmplx	c_sub(t_cmplx z1, t_cmplx z2)
{
	t_cmplx	diff;

	diff.rl = z1.rl - z2.rl;
	diff.im = z1.im - z2.im;
	return (diff);
}

t_cmplx	c_mult(t_cmplx z1, t_cmplx z2)
{
	t_cmplx	prod;
	
	prod.rl = z1.rl * z2.rl - z1.im * z2.im;
	prod.im = z1.rl * z2.im + z1.im * z2.rl;
	return (prod);
}

t_cmplx c_pow(t_cmplx z, int exp)
{
	t_cmplx	res;
	int		i;

	i = 1;
	// res.rl = 1;
	// res.im = 0;
	res = z;
	while (i++ < exp)
		res = c_mult(res, z);
	return (res);
}

t_cmplx c_sqr(t_cmplx z)
{
	t_cmplx	sqr;

	sqr.rl = z.rl * z.rl - z.im * z.im;
	sqr.im = 2 * z.rl * z.im;
	return (sqr);
}

t_cmplx c_sqr_plus_const(t_cmplx z, t_cmplx c)
{
	t_cmplx	res;

	res.rl = z.rl * z.rl - z.im * z.im + c.rl;
	res.im = 2 * z.rl * z.im + c.im;
	return (res);
}

double	c_dist_sqr(t_cmplx z)
{
	return (z.rl * z.rl + z.im * z.im);
}
