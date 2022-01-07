/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:53:04 by jaehwkim          #+#    #+#             */
/*   Updated: 2021/12/24 12:57:23 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# if OPEN_MAX > 12800
#  define ARRAY_MAX OPEN_MAX
# endif

# if OPEN_MAX <= 12800
#  define ARRAY_MAX 12800
# endif

int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*how_to_read(int fd, char *static_buffer);
char	*put_line(char *static_buffer);
char	*new_buffer(char *static_buffer);
char	*get_next_line(int fd);

#endif