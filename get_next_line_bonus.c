/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:43:29 by gfrancis          #+#    #+#             */
/*   Updated: 2023/05/25 16:45:25 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *content)
{
	char	*line;
	int		i;

	i = 0;
	if (!ft_strlen(content))
	{
		free(content);
		return (NULL);
	}
	while (content[i] != '\0' && content[i] != '\n')
		i++;
	if (content[i] == '\0')
		i--;
	line = ft_substr(content, 0, i + 1, 0);
	return (line);
}

char	*ft_read_file(int fd, char *content)
{
	char	*line;
	int		reader;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	reader = 1;
	while (!ft_strrchr(content, '\n') && reader)
	{
		reader = read(fd, line, BUFFER_SIZE);
		if (reader < 0)
		{
			free (line);
			free (content);
			return (NULL);
		}
		line[reader] = '\0';
		content = ft_strjoin(content, line);
	}
	free(line);
	return (content);
}

char	*get_next_line(int fd)
{
	static char		*content[FOPEN_MAX];
	char			*get_line;
	int				content_len;
	int				get_line_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	content[fd] = ft_read_file(fd, content[fd]);
	get_line = ft_get_line(content[fd]);
	if (!get_line)
	{
		content[fd] = NULL;
		return (NULL);
	}
	get_line_len = ft_strlen(get_line);
	content_len = ft_strlen(content[fd]);
	content[fd] = ft_substr(content[fd], get_line_len,
			content_len - get_line_len, 1);
	return (get_line);
}
