/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:32:09 by chourri           #+#    #+#             */
/*   Updated: 2024/05/17 16:39:26 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double real, double imaginary, t_data *DATA)
{
	int		iterations;
	double	swap;

	iterations = 1;
	while ((real * real + imaginary
			* imaginary) <= 4 && iterations < MAX_ITERATION)
	{
		swap = real * real - imaginary * imaginary + DATA->real_julia;
		imaginary = 2 * real * imaginary + DATA->imaginary_julia;
		real = swap;
		iterations++;
	}
	return (iterations);
}

int	mandelbrot(double real, double imaginary)
{
	int		iterations;
	double	rl;
	double	img;
	double	swap;

	iterations = 1;
	rl = real;
	img = imaginary;
	while ((real * real + imaginary * imaginary) <= 4
		&& iterations < MAX_ITERATION)
	{
		swap = real * real - imaginary * imaginary + rl;
		imaginary = 2 * real * imaginary + img;
		real = swap;
		iterations++;
	}
	return (iterations);
}
