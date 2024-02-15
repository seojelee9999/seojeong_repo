/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:30:14 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/29 12:52:25 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_buffer(int fd, char *buffer)
{
	char	*tmp_buffer;

	tmp_buffer = (char *)calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!tmp_buffer)
	{
		if (buffer)
			free (buffer);
		return (0);
	}
	buffer = get_buffer_extend(fd, tmp_buffer, buffer);
	if (buffer == 0)
	{
		free (tmp_buffer);
		return (0);
	}
	free (tmp_buffer);
	return (buffer);
}

char	*get_buffer_extend(int fd, char *tmp_buffer, char *buffer)
{
	int	return_read;

	return_read = 1;
	while (return_read > 0 && !check_next_line(buffer))
	{
		return_read = read(fd, tmp_buffer, BUFFER_SIZE);
		if (return_read < 0)
		{
			if (buffer)
				free (buffer);
			return (0);
		}
		tmp_buffer[return_read] = 0;
		buffer = ft_strjoin(buffer, tmp_buffer);
		if (!buffer)
			return (0);
		if (buffer[0] == 0)
		{
			free (buffer);
			return (0);
		}
	}
	return (buffer);
}

char	*get_line1(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i])
		if (buffer[i++] == '\n')
			break ;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
	{
		return (0);
	}
	ft_strlcpy(line, buffer, i + 1);
	return (line);
}

char	*after_buffer(char *buffer)
{
	int		i;
	int		len;
	char	*new_buffer;

	len = ft_strlen(buffer);
	i = 0;
	while (buffer[i])
		if (buffer[i++] == '\n')
			break ;
	new_buffer = (char *)malloc(sizeof(char) * (len - i + 1));
	if (new_buffer == 0)
	{
		free (buffer);
		return (0);
	}
	ft_strlcpy (new_buffer, buffer + i, len - i + 1);
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = get_buffer(fd, buffer);
	if (buffer == 0)
		return (0);
	line = get_line1(buffer);
	if (!line)
	{
		free (buffer);
		buffer = 0;
		return (0);
	}
	buffer = after_buffer(buffer);
	if (!buffer)
	{
		buffer = 0;
		free (line);
		return (0);
	}
	return (line);
}
