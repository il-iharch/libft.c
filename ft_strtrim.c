/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:28:13 by iharch            #+#    #+#             */
/*   Updated: 2024/11/12 11:53:53 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				break ;
			j++;
		}
		if (s1[i] != s2[j])
			break ;
		i++;
	}
	return (i);
}

static int	end(char *s1, char *s2)
{
	int	b;
	int	j;

	b = ft_strlen(s1);
	while (b--)
	{
		j = 0;
		while (s2[j])
		{
			if (s1[b] == s2[j])
				break ;
			j++;
		}
		if (s1[b] != s2[j])
			break ;
	}
	return (b);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		j;
	int		a;
	int		b;

	if (!s1 || !set)
		return (NULL);
	a = start((char *)s1, (char *)set);
	b = end((char *)s1, (char *)set);
	if (s1[0] == '\0' || (size_t)a == ft_strlen(s1))
		return (ft_strdup(""));
	s2 = malloc(((b - a) + 2) * sizeof(char));
	if (!s2)
		return (NULL);
	j = 0;
	while (a <= b)
	{
		s2[j++] = s1[a++];
	}
	s2[j] = '\0';
	return ((char *)(s2));
}
