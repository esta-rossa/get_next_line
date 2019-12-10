/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:22:39 by arraji            #+#    #+#             */
/*   Updated: 2019/12/10 12:24:14 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

size_t			ft_strlen(char const *str, int type);
void			ft_strcpy(char *dest, const char *src);
int				is_line(char *str, int rd);
int				ft_strjoin(char **s1, char *s2);
int				cutter(char **save, char **line);
char			*ft_strdup(char *src);
int				get_next_line(int fd, char **line);
int				end(char **s1, char **s2, int rt);
#endif
