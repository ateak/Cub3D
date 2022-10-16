/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:16:36 by ateak             #+#    #+#             */
/*   Updated: 2022/10/16 17:19:53 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_file_and_form_tail(int fd, char *tail);
char	*ft_create_tail(char *buf, char *tail);
char	*ft_create_line(char *tail);
char	*ft_new_tail(char *tail);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(const char *s, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

#endif
