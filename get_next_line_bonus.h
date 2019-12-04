/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:24:14 by arraji            #+#    #+#             */
/*   Updated: 2019/11/18 21:24:11 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1
size_t			ft_strlen(char const *str, int type);
void			ft_strcpy(char *dest, const char *src);
int				is_line(char *str, int rd);
int				ft_strjoin(char **s1, char *s2, size_t len);
int				cutter(char **save, char **line);
char			*ft_strdup(char *src);
int				get_next_line(int fd, char **line);
int				end(char **s1, char **s2, int rt);
#endif
