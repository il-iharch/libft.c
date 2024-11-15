/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:40:52 by iharch            #+#    #+#             */
/*   Updated: 2024/11/14 13:13:06 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	d;
	size_t	j;

	s = ft_strlen(src);
	if (!dstsize)
		return (s);
	d = ft_strlen(dst);
	if (dstsize <= d || dstsize == 0)
		return (s + dstsize);
	j = 0;
	while (src[j] && (d + j < dstsize - 1))
	{
		dst[d + j] = src[j];
		j++;
	}
	dst[d + j] = '\0';
	return (d + s);
}
