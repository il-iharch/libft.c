/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:11:59 by iharch            #+#    #+#             */
/*   Updated: 2024/11/14 12:50:19 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_skip(char *str, int i, int *s)
{
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*s = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long	r;
	int		s;
	int		i;

	r = 0;
	s = 1;
	i = 0;
	i = ft_skip((char *)str, i, &s);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r > (LONG_MAX - (str[i] - 48)) / 10)
		{
			if (s > 0)
				return (-1);
			else if (s < 0)
				return (0);
		}
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (r * s);
}
