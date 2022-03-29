/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:57:55 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/29 12:15:47 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

char	*get_path(char *command, char **envp)
{
	char	**paths;
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 6) == 0)
		++i;
	paths = ft_split(envp[i] + 5, ':');
	if (paths == 0)
		error();
	i = 0;
	while (paths[i] != 0)
	{
		temp = ft_strjoin("/", command);
		path = ft_strjoin(paths[i], temp);
		free(temp);
		if (access(path, X_OK) == 0)
			return (path);
		++i;
		ft_str_free(path);
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[i++] != 0)
	{
		cnt++;
	}
	return (cnt);
}

void	ft_str_free(char *str)
{
	free(str);
	str = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (new_str == 0)
		return (0);
	while (i < ft_strlen(s1))
	{
		new_str[i] = s1[i];
		j = 0;
		i++;
	}
	while (j <= ft_strlen(s2))
	{
		new_str[i] = s2[j];
		j++;
		i++;
	}
	return (new_str);
}
