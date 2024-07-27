/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:19:51 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/27 03:32:16 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fr;
	
	if ((argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 10) == 0) ||
	(argc == 4 && ft_strncmp(argv[1], "Julia", 5) == 0))
	{
		init_data(&fr, argv);
		init_fractal(&fr);
		// render_fractal(&fr);
		init_events(&fr);
		mlx_loop(fr.mlx);
	}
	else
		arg_error(1);

	mlx_terminate(fr.mlx);
	return (0);
}
