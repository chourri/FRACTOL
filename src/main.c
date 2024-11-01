/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:45:10 by chourri           #+#    #+#             */
/*   Updated: 2024/05/21 10:08:26 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	*data;

	check(ac, av);
	initialize(&data, av);
	draw_image(data);
	hooks(data);
	mlx_loop(data->mlx);
	return (0);
}
