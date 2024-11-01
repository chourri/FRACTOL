/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:31:23 by chourri           #+#    #+#             */
/*   Updated: 2024/05/20 16:30:53 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_window(t_data *DATA)
{
	mlx_destroy_window(DATA->mlx, DATA->window);
	exit(0);
}

static int	keyhook(int keycode, t_data *DATA)
{
	if (keycode == LEFT)
		DATA->offset_x -= 0.5 * DATA->zoom;
	else if (keycode == RIGHT)
		DATA->offset_x += 0.5 * DATA->zoom;
	else if (keycode == UP)
		DATA->offset_y -= 0.5 * DATA->zoom;
	else if (keycode == BOTTOM)
		DATA->offset_y += 0.5 * DATA->zoom;
	else if (keycode == 53)
		close_window(DATA);
	draw_image(DATA);
	return (0);
}

static int	mousehook(int keycode, int x, int y, t_data *DATA)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		DATA->zoom *= 0.8;
	else if (keycode == 5)
		DATA->zoom *= 1.2;
	draw_image(DATA);
	return (0);
}

void	hooks(t_data *DATA)
{
	mlx_key_hook(DATA->window, keyhook, DATA);
	mlx_hook(DATA->window, 4, 0, mousehook, DATA);
	mlx_hook(DATA->window, 17, 0, close_window, DATA);
}
