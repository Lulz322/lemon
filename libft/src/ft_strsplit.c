/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:28:27 by iruban            #+#    #+#             */
/*   Updated: 2018/11/05 13:37:57 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		words(const char *s, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			word++;
		i++;
	}
	if (s[0] != '\0')
		word++;
	return (word);
}

static char		**create_array(const char *s, char c, char **ret)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c))
				len++;
			ret[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	ret[j] = 0;
	return (ret);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tmp;

	if (!s || !c)
		return (0);
	if (!(tmp = (char **)malloc(sizeof(s) * (words(s, c) + 2))))
		return (NULL);
	tmp = create_array(s, c, tmp);
	return (tmp);
}
