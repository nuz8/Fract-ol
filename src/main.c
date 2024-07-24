/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:35:36 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/23 04:18:30 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(void)
{
	t_cmplx	z_n;
	t_cmplx	z_nxt;
	t_cmplx	c;
	int		i;
	double	dist;

	z_n.rl = 0;
	z_n.im = 0;
	c.rl = 0.25;
	c.im = 1;

	i = 0;
	dist = 0;
	while (dist <= 2 && i++ < MAX_ITER)
	{
		z_nxt = get_next_point(z_n, c);
		printf_cmplx(z_nxt);
		printf("\n");
		dist = c_distance(z_nxt);
		printf_float("dist1", dist);
		printf("\n");
		z_n = z_nxt;
	}
	write(1, "\n", 1);

	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_fractal	fr;
	
// 	if ()
// }