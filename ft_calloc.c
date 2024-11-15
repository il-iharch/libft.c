/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:50:57 by iharch            #+#    #+#             */
/*   Updated: 2024/11/15 12:04:29 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libc.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*a;

	if ((int) count < 0 || (int) size < 0)
		return (NULL);
	if ((count * size) > SIZE_MAX)
		return (NULL);
	a = malloc(count * size);
	if (!a)
		return (NULL);
	ft_bzero(a, count * size);
	return (a);
}
