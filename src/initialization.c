/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:34:19 by chourri           #+#    #+#             */
/*   Updated: 2024/05/17 15:39:06 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_var(t_data **DATA, char **av)
{
	if (!ft_strcmp(av[1], "mandelbrot"))
		(*DATA)->fractal = MANDELBROT;
	else
	{
		(*DATA)->fractal = JULIA;
		(*DATA)->real_julia = to_double(av[2]);
		(*DATA)->imaginary_julia = to_double(av[3]);
	}
	(*DATA)->zoom = 1.0;
	(*DATA)->offset_x = 0.0;
	(*DATA)->offset_y = 0.0;
}

void	init_mlx(t_data **DATA)
{
	(*DATA)->mlx = mlx_init();
	if (!(*DATA)->mlx)
		exit(EXIT_FAILURE);
	(*DATA)->window = mlx_new_window((*DATA)->mlx, WIDTH, HEIGHT, "Fractal");
	if (!(*DATA)->window)
		exit(EXIT_FAILURE);
	(*DATA)->img = mlx_new_image((*DATA)->mlx, WIDTH, HEIGHT);
	if (!(*DATA)->img)
	{
		mlx_destroy_window((*DATA)->mlx, (*DATA)->window);
		exit(EXIT_FAILURE);
	}
	(*DATA)->address = mlx_get_data_addr((*DATA)->img,
			&(*DATA)->bit_pp, &(*DATA)->line_len, &(*DATA)->endian);
	if (!(*DATA)->address)
	{
		mlx_destroy_image((*DATA)->mlx, (*DATA)->img);
		mlx_destroy_window((*DATA)->mlx, (*DATA)->window);
		exit(EXIT_FAILURE);
	}
}

void	initialize(t_data **DATA, char **av)
{
	(*DATA) = (t_data *)malloc(sizeof(t_data));
	if (!(*DATA))
		exit(EXIT_FAILURE);
	init_var(DATA, av);
	init_mlx(DATA);
}
