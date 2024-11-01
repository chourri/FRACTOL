/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:55:13 by chourri           #+#    #+#             */
/*   Updated: 2024/05/21 10:52:52 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define WIDTH 500
# define HEIGHT 500
# define UP 126
# define BOTTOM 125
# define LEFT 123
# define RIGHT 124
# define MAX_ITERATION 1500
# define MANDELBROT 1
# define JULIA 0

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*img;
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	real_julia;
	double	imaginary_julia;
	int		fractal;
	char	*address;
	int		bit_pp;
	int		line_len;
	int		endian;
}	t_data;

void	check(int ac, char **av);
void	error(void);
int		julia(double real, double imaginary, t_data *DATA);
int		mandelbrot(double real, double imaginary);
void	initialize(t_data **DATA, char **av);
void	draw_image(t_data	*DATA);
int		ft_strcmp(char *str1, char *str2);
double	to_double(char *s);
int		get_trgb(int iters);
void	hooks(t_data *DATA);

#endif
