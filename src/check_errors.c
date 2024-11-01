/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:33:14 by chourri           #+#    #+#             */
/*   Updated: 2024/05/21 10:01:23 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_numbers(char *av)
{
	int	i;
	int	dot;

	i = 1;
	dot = 0;
	if (av[0] != '+' && av[0] != '-' && !(av[0] >= '0' && av[0] <= '9'))
		return (0);
	if ((av[0] == '+' || av[0] == '-') && !(av[1] >= '0' && av[1] <= '9'))
		return (0);
	while (av[i])
	{
		if (av[i] == '.')
			dot++;
		if (av[i] == '.' && !(av[i + 1] >= '0' && av[i + 1] <= '9'))
			return (0);
		if (!((av[i] >= '0' && av[i] <= '9') || av[i] == '.') || dot > 1)
			return (0);
		i++;
	}
	return (1);
}

void	check(int ac, char **av)
{
	if (WIDTH > 5120 || HEIGHT > 2880 || WIDTH < 0
		|| HEIGHT < 0 || MAX_ITERATION < 1)
		error();
	if (ac != 2 && ac != 4)
		error();
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		return ;
	if (ac == 4 && !ft_strcmp(av[1], "julia"))
	{
		if (check_numbers(av[2]) && check_numbers(av[3]))
			return ;
		error();
	}
	error();
}

void	error(void)
{
	write(STDERR_FILENO, "invalid input\n", 14);
	write(STDERR_FILENO, "Available options : \n", 22);
	write(STDERR_FILENO, "[OPTION 1] :\t./fractol mandelbrot\n", 34);
	write(STDERR_FILENO, "[OPTION 2] :\t./fractol julia ", 60);
	write(STDERR_FILENO, "real[double] imaginary[double]\n", 31);
	exit(EXIT_FAILURE);
}
