/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:02:44 by ateak             #+#    #+#             */
/*   Updated: 2022/10/16 17:27:54 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_tail(char *tail)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (tail[i] && tail[i] != '\n')
		i++;
	if (!tail[i]) // tail[i] == null
	{
		free(tail);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(tail) - i));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (tail[i])
		str[j++] = tail[i++];
	str[j] = '\0';
	free(tail);
	return (str);
}

char	*ft_create_line(char *tail)
{
	char	*substr;
	int		i;
	int		substr_len;

	i = 0;
	if (!tail[i])
		return (NULL);
	while (tail[i] && tail[i] != '\n')
		i++;
	substr_len = i;
	substr = (char *)malloc(sizeof(char) * (substr_len + 2));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (substr_len >= 0)
	{
		substr[i] = tail[i];
		i++;
		substr_len--;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_create_tail(char *buf, char *tail)
{
	char	*tmp;

	if (!tail)
	{
		tail = (char *)malloc(1 * sizeof(char));
		tail[0] = '\0';
	}
	if (!tail || !buf)
		return (NULL);
	tmp = tail;
	tail = ft_strjoin_gnl(tail, buf);
	free(tmp);
	return (tail);
}

char	*ft_read_file_and_form_tail(int fd, char *tail)
{
	char	*buf;
	ssize_t	read_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr_gnl(tail, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		tail = ft_create_tail(buf, tail);
	}
	free(buf);
	return (tail);
}

char	*get_next_line(int fd)
{
	static char	*tail;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tail = ft_read_file_and_form_tail(fd, tail);
	if (!tail)
		return (NULL);
	line = ft_create_line(tail);
	tail = ft_new_tail(tail);
	return (line);
}
