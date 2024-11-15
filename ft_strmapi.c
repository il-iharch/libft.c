/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:27:17 by iharch            #+#    #+#             */
/*   Updated: 2024/11/14 13:13:38 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char ))
{
	char	*s1;
	int		i;
	int		a;
	int		c;

	if (!s || !f)
		return (NULL);
	i = 0;
	a = ft_strlen(s);
	s1 = malloc((a + 1) * sizeof(char));
	if (!s1)
		return (NULL);
	while ((char)s[i])
	{
		c = s[i];
		s1[i] = f(i, c);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
