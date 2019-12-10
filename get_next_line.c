/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:22:34 by arraji            #+#    #+#             */
/*   Updated: 2019/12/10 12:24:03 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			end(char **s1, char **s2, int rt)
{
	if (s1 != NULL && *s1 != NULL)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 != NULL && *s2 != NULL)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (rt);
}

static	int	finish(char **line, char **save, char **buff)
{
	if (!(*line = ft_strdup("")))
		return (end(save, buff, -1));
	return (end(save, buff, 0));
}

int			get_next_line(int fd, char **line)
{
	long	long		rd;
	static	char		*save = NULL;
	char				*buff;

	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (end(&save, NULL, -1));
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (end(&buff, &save, -1));
	rd = 1;
	while (!is_line(save, rd))
	{
		if ((rd = read(fd, buff, BUFFER_SIZE)) == -1)
			return (end(&buff, &save, -1));
		buff[rd] = '\0';
		save = save == NULL ? (char *)malloc(rd + 1) : save;
		if (!save)
			return (end(&buff, NULL, -1));
		if (ft_strjoin(&save, buff) == -1)
			return (end(&buff, &save, -1));
		if (!rd && !ft_strlen(save, 1))
			return (finish(line, &save, &buff));
	}
	return (end(&buff, NULL, cutter(&save, line)));
}
