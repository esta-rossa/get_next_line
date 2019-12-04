/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:17:39 by arraji            #+#    #+#             */
/*   Updated: 2019/11/18 04:38:28 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t			ft_strlen(char const *str, int type)
{
	size_t len;

	len = 0;
	if (str == NULL)
		return (0);
	if (type == 1)
		while (str[len])
			len -= -1;
	if (type == 0)
		while (str[len] != '\n' && str[len] != '\0')
			len -= -1;
	return (len);
}

char			*ft_strdup(char *src)
{
	int		len;
	char	*str;
	int		i;

	len = 0;
	i = -1;
	while (src[len] != '\0')
		len++;
	if (!(str = (char*)malloc((len + 1))))
		return (NULL);
	while (src[++i] != '\0')
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}

int				is_line(char *str, int rd)
{
	int index;

	index = 0;
	if (!str)
		return (0);
	if (!rd)
		return (1);
	while (str[index])
		if (str[index++] == '\n')
			return (1);
	return (0);
}

int				ft_strjoin(char **s1, char *s2, size_t len)
{
	size_t	index;
	size_t	jndex;
	size_t	s1_len;
	size_t	s2_len;
	char	*copy;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	index = 0;
	jndex = 0;
	if (!(copy = ft_strdup(*s1)))
		return (end(s1, NULL, -1));
	s1_len = ft_strlen(copy, 1);
	s2_len = ft_strlen(s2, 1);
	free(*s1);
	if (!(*s1 = (char *)malloc(s1_len + s2_len + 1)))
		return (end(&copy, NULL, -1));
	while (jndex < s1_len)
		(*s1)[index++] = copy[jndex++];
	jndex = 0;
	while (jndex < s2_len && jndex < len)
		(*s1)[index++] = s2[jndex++];
	(*s1)[index] = '\0';
	return (end(&copy, NULL, 1));
}

int				cutter(char **save, char **line)
{
	int		index;
	int		jndex;
	char	*copy;

	index = 0;
	jndex = 0;
	if (!(copy = ft_strdup(*save)))
		return (end(save, NULL, -1));
	free(*save);
	if (!(*line = (char *)malloc(ft_strlen(copy, 0) + 1)))
		return (end(&copy, NULL, -1));
	if (!(*save = malloc(ft_strlen(copy, 1) - ft_strlen(copy, 0) + 1)))
		return (end(&copy, line, -1));
	while (copy[index] != '\n' && copy[index] != '\0')
	{
		(*line)[index] = copy[index];
		index++;
	}
	(*line)[index] = '\0';
	if (copy[index] == '\n')
		index -= -1;
	while (copy[index] != '\0')
		(*save)[jndex++] = copy[index++];
	(*save)[jndex] = '\0';
	return (end(&copy, NULL, 1));
}
