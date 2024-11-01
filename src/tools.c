/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:23:15 by chourri           #+#    #+#             */
/*   Updated: 2024/05/21 10:39:15 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while ((str1[i] || str2[i]))
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((unsigned char )str1[i] - (unsigned char)str2[i]);
	}
	return (0);
}

static void	check_sign(int *i, int *sign, char *s)
{
	if (s[*i] == '-')
		*sign = -1 + (*i)++;
	else if (s[*i] == '+')
		(*i)++;
}

double	to_double(char *s)
{
	int			i;
	int			sign;
	double		result;
	long long	p;

	i = 0;
	sign = 1;
	result = 0;
	p = 10;
	check_sign(&i, &sign, s);
	while (s[i] && s[i] != '.')
		result = result * 10 + s[i++] - '0';
	if (s[i] == '.')
		i++;
	while (s[i])
	{
		if (p > LLONG_MAX / 10)
			break ;
		result += (double)(s[i++] - '0') / p;
		p *= 10;
	}
	if (result >= 4)
		error();
	return (result * sign);
}
