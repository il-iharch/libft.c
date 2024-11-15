/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:16:42 by iharch            #+#    #+#             */
/*   Updated: 2024/11/14 13:04:34 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *s, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			a++;
		if (s[i])
			i++;
	}
	return (a);
}

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	*ft_dup(char const *s, char c, int st)
{
	char	*str;
	int		j;
	int		i;
	int		a;

	j = 0;
	a = 0;
	i = st;
	while (s[i] && s[i] != c)
	{
		i++;
		a++;
	}
	str = malloc((a + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (j < a)
	{
		str[j] = s[st + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	str = malloc((ft_count((char *)s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_count((char *)s, c))
	{
		if (s[i] && s[i] != c)
		{
			str[j] = ft_dup(s, c, i);
			if (str[j] == NULL)
				return (ft_free(str), NULL);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
		i++;
	}
	return (str[j] = NULL, str);
}
