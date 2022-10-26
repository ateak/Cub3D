/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:42:55 by ateak             #+#    #+#             */
/*   Updated: 2022/10/26 18:44:55 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char **str)
{
	if (*str != NULL && str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

static int	ft_line(char **rest, char **line)
{
	char	*ptrn;
	char	*tmp;

	ptrn = NULL;
	tmp = NULL;
	ptrn = ft_strchr(*rest, '\n');
	if (ptrn)
	{
		*ptrn = '\0';
		tmp = *rest;
		*line = ft_strdup(tmp);
		ptrn++;
		*rest = ft_strdup(ptrn);
		ft_free(&tmp);
	}
	else
	{
		tmp = *line;
		*line = ft_strdup(*rest);
		ft_free(rest);
		return (0);
	}
	return (1);
}

static int	ft_exit(char **rest, char **line, int fd_read)
{
	if (fd_read == 0)
	{
		if (*rest)
			return (ft_line(rest, line));
		else
			*line = ft_strdup("");
		return (0);
	}
	else
		return (ft_line(rest, line));
}

static int	ft_read(int fd, char *buf, int *fd_read)
{
	*fd_read = (int)read(fd, buf, BUFFER_SIZE);
	return (*fd_read);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			fd_read;
	static char	*rest;
	char		*tmp;

	if ((read(fd, 0, 0) < 0) || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((ft_read(fd, buf, &fd_read)) > 0)
	{
		buf[fd_read] = '\0';
		if (rest == NULL)
			rest = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(rest, buf);
			ft_free(&rest);
			rest = tmp;
			tmp = NULL;
		}
		if (ft_strchr(rest, '\n'))
			break ;
	}
	ft_free(&buf);
	return (ft_exit(&rest, line, fd_read));
}
