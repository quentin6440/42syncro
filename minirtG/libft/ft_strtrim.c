/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:30:57 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/21 13:30:58 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	p = NULL;
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set,s1[start]) && start < end)
		start++;
	while (ft_strchr(set, s1[end - 1]) && start < end)
		end--;
	p = ft_substr(s1, start, end - start);
	if (!p)
		return (NULL);
	return p;
}
