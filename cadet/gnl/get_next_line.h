/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:21:30 by hyunjung          #+#    #+#             */
/*   Updated: 2022/01/06 17:14:30 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// # if OPEN_MAX > 12800
// #  define ARRAY_MAX OPEN_MAX
// # endif

// # if OPEN_MAX <= 12800
// #  define ARRAY_MAX 12800
// # endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_lstr(int fd, char *lstr);
char	*ft_get_line(char *lstr);
char	*ft_reset_lstr(char *lstr);
char	*get_next_line(int fd);

#endif