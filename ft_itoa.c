/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:55:44 by iharch            #+#    #+#             */
/*   Updated: 2024/11/14 11:31:14 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int i)
{
	int	k;

	k = 0;
	if (i <= 0)
		k = 1;
	while (i)
	{
		i = i / 10;
		k++;
	}
	return (k);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		k;

	k = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc ((k + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[k] = '\0';
	if (n == 0)
		str[--k] = '0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (n != 0)
	{
		str[--k] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
