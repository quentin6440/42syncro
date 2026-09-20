/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:23:35 by qcyril-a          #+#    #+#             */
/*   Updated: 2025/10/11 16:25:37 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static void ft_free_all(char **arr, size_t k)
{
	if (!arr)
		return ;
	while (k > 0)
	{
		k--;
		free(arr[k]);
	}
	free(arr);
}

static size_t	ft_ctsections(char const *s, char delimiter)
{
	size_t	nsections;

	if (!s)
		return (0);
	nsections = 0;
	while (*s)
	{
		if (*s == delimiter)
		{
			while (*s == delimiter && *s)
				s++;
		}
		else
		{
			while (*s != delimiter && *s)
				s++;
			nsections++;
		}
	}
	return (nsections);
}

static int	ft_extractsection(char **section, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			section[k] = ft_substr(s, i, j - i);
			if (!section[k])
			{
				ft_free_all(section, k);
				return (1);
			}
			k++;
			i = j;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**myarr;

	myarr = NULL;
	if (s == NULL)
	{
		myarr = ft_calloc(1, sizeof(char *));
		if (!myarr)
			return (NULL);
		myarr[0] = NULL;
		return (myarr);
	}
	myarr = ft_calloc((ft_ctsections(s, c) + 1), sizeof(char *));
	if (!myarr)
		return (NULL);
	if (ft_extractsection(myarr, s, c))
		return (NULL);
	return (myarr);
}
