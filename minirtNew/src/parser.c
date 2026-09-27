/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:34:00 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/21 13:34:01 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minirt.h"

int	ft_parse_line(char **tokens, t_scene *scene)
{
	if (!tokens || !tokens[0])
		return (0);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		return (ft_parse_ambient(tokens, scene));
	if (ft_strncmp(tokens[0], "C", 2) == 0)
		return (ft_parse_camera(tokens, scene));
	if (ft_strncmp(tokens[0], "L", 2) == 0)
		return (ft_parse_light(tokens, scene));
	if (ft_strncmp(tokens[0], "sp", 3) == 0)
		return (ft_parse_obj(tokens, scene, SPHERE));
	if (ft_strncmp(tokens[0], "pl", 3) == 0)
		return (ft_parse_obj(tokens, scene, PLANE));
	if (ft_strncmp(tokens[0], "cy", 3) == 0)
		return (ft_parse_obj(tokens, scene, CYLINDER));
	return (-1);
}

int	ft_parse_rt(int fd, t_scene *scene)
{
	char	*raw_line;
	char	*clean_line;
	char	**tokens;

	raw_line = get_next_line(fd);
	while (raw_line != NULL)
	{
		clean_line = ft_strtrim(raw_line, " \t\r\n\v\f");
		free(raw_line);
		if (clean_line && clean_line[0] != '\0' && clean_line[0] != '#')
		{
			tokens = ft_split(clean_line, ' ');
			if (!tokens || ft_parse_line(tokens, scene) < 0)
			{
				free(clean_line);
				ft_free_tab(tokens);
				return (-1);
			}
			ft_free_tab(tokens);
		}
		free(clean_line);
		raw_line = get_next_line(fd);
	}
	return (0);
}