/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:49:36 by arraji            #+#    #+#             */
/*   Updated: 2019/11/18 21:18:10 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	end(char **s1, char **s2, int rt)
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

int	get_next_line(int fd, char **line)
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
		if (!rd && !ft_strlen(save, 1))
			return (end(&save, &buff, 0));
		if (ft_strjoin(&save, buff, rd) == -1)
			return (end(&buff, &save, -1));
	}
	return (end(&buff, NULL, cutter(&save, line)));
}
