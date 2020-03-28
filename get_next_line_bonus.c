/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 16:22:58 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/28 23:40:45 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	set_new_str(char **line, char **save)
{
	int		size;
	int		locate;
	int		result;
	char	*tmp_str;

	size = 0;
	while ((*save)[size] && (*save)[size] != '\n')
		size++;
	*line = (char *)malloc(size + 1);
	locate = 0;
	while (locate < size)
	{
		(*line)[locate] = (*save)[locate];
		locate++;
	}
	(*line)[locate] = '\0';
	result = (((*save)[size] == '\n') ? READ : READ_EOF);
	tmp_str = (result ? ft_strpush(*save, size + 1) : ft_strnul());
	if (result == READ_EOF)
		free(*save);
	*save = tmp_str;
	return (result);
}

int	final_reset(char **line)
{
	*line = ft_strnul();
	return (READ_EOF);
}

int	get_next_line(int fd, char **line)
{
	long long	len;
	char		buff[BUFFER_SIZE + 1];
	static char	*str[FD_SIZE];
	char		*tmp_str;

	if (fd < 0 || !line || fd >= FD_SIZE || \
			BUFFER_SIZE <= 0 || read(fd, buff, 0))
		return (ERROR);
	if (!str[fd])
		str[fd] = ft_strnul();
	len = 0;
	while (!(ft_strchr(str[fd], '\n')) && \
			((len = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[len] = '\0';
		tmp_str = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp_str;
	}
	if (len < 0)
		return (ERROR);
	if (len == 0 && str[fd][0] == '\0')
		return (final_reset(line));
	return (set_new_str(line, &(str[fd])));
}
