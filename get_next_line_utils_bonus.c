/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 16:21:12 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/28 23:30:19 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnul(void)
{
	char	*result;

	result = (char *)malloc(1);
	*result = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	return ((*s) ? 1 + ft_strlen(s + 1) : 0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		locate;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result)
	{
		locate = 0;
		while (*s1)
		{
			result[locate++] = *s1;
			s1++;
		}
		while (*s2)
		{
			result[locate++] = *s2;
			s2++;
		}
		result[locate] = '\0';
	}
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int		is_end;
	char	*now;

	is_end = 0;
	now = (char *)s;
	while (1)
	{
		if (*now == c)
			break;
		if (*now == '\0')
		{
			is_end = 1;
			break;
		}
		now++;
	}
	return ((is_end) ? NULL : now);
}

char	*ft_strpush(char *s, int push)
{
	int	locate;

	locate = 0;
	while (s[locate + push])
	{
		s[locate] = s[locate + push];
		locate++;
	}
	while (s[locate])
		s[locate++] = '\0';
	return (s);
}
