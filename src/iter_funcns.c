/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_funcns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 03:39:50 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/23 04:17:41 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_cmplx	get_next_point(t_cmplx z_n, t_cmplx c);

t_cmplx	get_next_point(t_cmplx z_n, t_cmplx c)
{
	t_cmplx	z_nxt;

	z_nxt = c_add(c_pow(z_n, 2), c);
	// z_nxt = c_add(c_sqr(z_n), c);
	// z_nxt = c_sqr_plus_c(z_n, c);
	return (z_nxt);
}