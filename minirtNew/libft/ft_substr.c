/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:31:00 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/21 13:31:01 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *p = NULL;
	size_t	len_s = ft_strlen(s);
	size_t i = 0;

	if ( !len || start > len_s)
		return ft_strdup("");
	if (len > len_s - start)
		len = len_s - start;
	p = malloc(len + 1);
	if (!p)
		return NULL;
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = 0;
	
	return p;
}
