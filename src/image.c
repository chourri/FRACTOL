/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:08:06 by chourri           #+#    #+#             */
/*   Updated: 2024/05/21 10:08:15 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *DATA, int x, int y, int color)
{
	char	*dest;
	int		offset;

	offset = y * DATA->line_len + x * (DATA->bit_pp / 8);
	dest = DATA->address + offset;
	*(unsigned int *)dest = color;
}

static void	put_pixels(int iter, t_data *DATA, int x, int y)
{
	if (iter == MAX_ITERATION)
		my_mlx_pixel_put(DATA, x, y, 0);
	else
		my_mlx_pixel_put(DATA, x, y, get_trgb(iter));
}

void	draw_image(t_data *DATA)
{
	int		x;
	int		y;
	double	real;
	double	imag;
	int		iter;

	x = -1;
	while (++x < WIDTH)
	{
		y = 0;
		real = DATA->zoom * ((double)4 * x / WIDTH - 2) + DATA->offset_x;
		while (y < HEIGHT)
		{
			imag = DATA->zoom * ((double)4 * y / HEIGHT - 2) + DATA->offset_y;
			if (DATA->fractal == MANDELBROT)
				iter = mandelbrot(real, imag);
			else
				iter = julia(real, imag, DATA);
			put_pixels(iter, DATA, x, y);
			y++;
		}
	}
	mlx_put_image_to_window(DATA->mlx, DATA->window, DATA->img, 0, 0);
}
