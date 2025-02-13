/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:20:29 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/07 14:28:19 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

static int	ensure_capacity(t_buffer *buffer, size_t additional_size)
{
	size_t	new_capacity;
	char	*new_data;

	if (buffer->capacity - buffer->length < additional_size)
	{
		if (buffer->capacity * 2 - buffer->length < additional_size)
			new_capacity = buffer->length + additional_size;
		else
			new_capacity = buffer->capacity * 2;
		new_data = malloc(new_capacity);
		if (!new_data)
			return (0);
		if (buffer->data)
			ft_memmove(new_data, buffer->data, buffer->length);
		free(buffer->data);
		buffer->data = new_data;
		buffer->capacity = new_capacity;
	}
	return (1);
}

static int	read_until_newline(int fd, t_buffer *buffer, char **newline_pos)
{
	size_t	search_start;
	ssize_t	bytes_read;

	search_start = 0;
	bytes_read = BUFFER_SIZE;
	while (1)
	{
		*newline_pos = ft_memchr(buffer->data + search_start, '\n',
				buffer->length - search_start);
		if (*newline_pos != NULL || bytes_read != BUFFER_SIZE)
			return (bytes_read);
		search_start = buffer->length;
		if (!ensure_capacity(buffer, BUFFER_SIZE))
			return (-1);
		bytes_read = read(fd, buffer->data + buffer->length, BUFFER_SIZE);
		if (bytes_read == -1)
			return (bytes_read);
		buffer->length += bytes_read;
	}
}

static char	*extract_line(t_buffer *buffer, char *newline_pos)
{
	size_t	line_length;
	char	*line;

	line_length = 0;
	if (newline_pos != NULL)
		line_length = newline_pos - buffer->data + 1;
	else if (buffer->length > 0)
		line_length = buffer->length;
	line = ft_strndup(buffer->data, line_length);
	if (!line)
		return (NULL);
	buffer->length -= line_length;
	ft_memmove(buffer->data, buffer->data + line_length, buffer->length);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	ssize_t			bytes_read;
	char			*newline_pos;
	char			*line;

	line = NULL;
	bytes_read = read_until_newline(fd, &buffer, &newline_pos);
	if (bytes_read != -1 && buffer.length > 0)
		line = extract_line(&buffer, newline_pos);
	if (bytes_read <= 0 || line == NULL)
	{
		free(buffer.data);
		buffer.data = NULL;
		buffer.length = 0;
		buffer.capacity = 0;
		if (bytes_read == -1 || line == NULL)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
	}
	return (line);
}
