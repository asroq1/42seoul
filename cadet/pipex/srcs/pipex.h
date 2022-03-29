/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:19:05 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/29 11:12:26 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

void			execute(char *argv, char **envp);
void			childProc(char **argv, char **envp, int *fd);
void			parentProc(char **argv, char **envp, int *fd);
void			error(void);
char			*get_path(char *command, char **envp);
char			*ft_strnstr(const char *str, const char *substr, int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, int start, int len);
int				ft_strlen(const char *str);
void			ft_str_free(char *str);

#endif
