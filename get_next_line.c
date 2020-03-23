/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 16:19:58 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/23 23:07:35 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_new_str(char **line, char *save)
{
	int		size;
	int		locate;

	size = 0;
	while (save[size] && save[size] != '\n')
		size++;
	*line = (char *)malloc(size + 1);
	locate = 0;
	while (locate < size)
	{
		(*line)[locate] = save[locate];
		locate++;
	}
	(*line)[locate] = '\0';
	return ((save[size] == '\n') ? ft_strdup(save + size + 1) : ft_strnul());
}

int			final_reset(char **line)
{
	*line = ft_strnul();
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int			len;
	char		buff[BUFFER_SIZE + 1];
	static char	*str[FD_SIZE];
	char		*tmp_str;

	if (fd < 0 || !line || fd > FD_SIZE || BUFFER_SIZE <= 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnul();
	while (!(ft_strchr(str[fd], '\n')) && (len = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[len] = '\0';
		tmp_str = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp_str;
	}
	if (len < 0)
		return (-1);
	if (len == 0 && ft_strlen(str[fd]) == 0)
		return (final_reset(line));
	tmp_str = set_new_str(line, str[fd]);
	free(str[fd]);
	if (*tmp_str)
		str[fd] = tmp_str;
	return ((*tmp_str) ? 1 : 0);
}
