/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:17:35 by joaseque          #+#    #+#             */
/*   Updated: 2026/03/21 17:55:01 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*update_line(char *buffer, ssize_t *error_flag)
{
	char	*new_buff;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (*error_flag = 0, NULL);
	}
	new_buff = malloc(ft_strlen(buffer) - i + 1);
	if (!new_buff)
		return (free(buffer), *error_flag = 1, NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buff[j++] = buffer[i++];
	new_buff[j] = '\0';
	free(buffer);
	return (*error_flag = 0, new_buff);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	ssize_t	i;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_line(int fd, char *buffer)
{
	char	*temp_buf;
	char	*temp2;
	ssize_t	bytes_read;

	if (!buffer)
		buffer = ft_strdup("");
	temp_buf = malloc(BUFFER_SIZE + 1);
	if (!temp_buf)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(temp_buf), NULL);
		temp_buf[bytes_read] = '\0';
		temp2 = ft_strjoin(buffer, temp_buf);
		free(buffer);
		buffer = temp2;
		if (!buffer)
			return (free(temp_buf), NULL);
	}
	free(temp_buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		error_flag;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = read_line(fd, buffer);
	if (!buffer || !*buffer)
		return (free(buffer), buffer = NULL, NULL);
	line = extract_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = update_line(buffer, &error_flag);
	if (!buffer && error_flag == 1)
		return (free(line), NULL);
	return (line);
}
