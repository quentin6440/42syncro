#include "../include/minirt.h"

static char	*ft_trim_line(char *line)
{
	char	*trimmed;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	trimmed = ft_substr(line, 0, i);
	free(line);
	return (trimmed);
}

int	ft_parse_rt(int fd, t_scene *scene)
{
	char	*raw_line;
	char	*line;
	char	**tokens;

	raw_line = get_next_line(fd);
	while (raw_line != NULL)
	{
		line = ft_trim_line(raw_line);
		if (line && line[0] != '\0' && line[0] != '#')
		{
			tokens = ft_split(line, ' ');
			
			if (!tokens || ft_parse_line(tokens, scene) < 0)
			{
				free(line);
				ft_free_tab(tokens);
				return (-1); // Remonte l'erreur au main() pour qu'il fasse le clean_exit
			}
			ft_free_tab(tokens);
		}
		free(line);
		raw_line = get_next_line(fd);
	}
	return (0);
}