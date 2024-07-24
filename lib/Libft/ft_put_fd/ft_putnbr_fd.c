/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:21:35 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/12 20:08:23 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	rem;
	long	ln;

	if (!fd)
		return ;
	ln = (long)n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	rem = ln % 10 + '0';
	if (ln >= 10)
	{
		ft_putnbr_fd(ln / 10, fd);
	}
	write(fd, &rem, 1);
}

void	ft_putlong_fd(long n, int fd)
{
	char	rem;
	long	ln;

	if (!fd)
		return ;
	if (n > LONG_MAX || n < LONG_MIN)
	{
		ft_putstr_fd("Error: long overflow\n", 2);
		return ;
	}
	ln = n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	rem = ln % 10 + '0';
	if (ln >= 10)
	{
		ft_putlong_fd(ln / 10, fd);
	}
	write(fd, &rem, 1);
}
