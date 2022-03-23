/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:57:55 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/23 18:55:28 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	printf("error");
}

void	execute(char *argv, char **envp)
{
	char	**command;
	char	*path;
	int		i;

	i = -1;
	command = ft_split(argv, ' ');
	printf("command => %c\n", command);
	path = get_path(command[0], envp);
	if (command == 0)
	{
		error();
	}
	if (execve(path, command, envp) == -1)
	{
		error();
	}
}

char	*get_path(char *command, char **envp)
{
	// char	**paths;
	// char	*path;
	// char	*part_path;
	// int		i;

	// i = 0;
	// while (ft_strnstr(envp[i], "PATH", 4) == 0)
	// 	i++;
	// paths = ft_split(envp[i] + 5, ':');
	// i = 0;
	// while (paths[i])
	// {
	// 	part_path = ft_strjoin(paths[i], "/");
	// 	path = ft_strjoin(part_path, command);
	// 	free(part_path);
	// 	if (access(path, F_OK) == 0)
	// 		return (path);
	// 	free(path);
	// 	i++;
	// }
	// i = -1;
	// while (paths[++i])
	// 	free(paths[i]);
	// free(paths);
	// return (0);
	char	**paths;
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		++i;
	paths = ft_split(envp[i] + 5, ':');
	// if (paths == 0)
	// 	error(ERR);
	i = 0;
	while (paths[i] != 0)
	{
		temp = ft_strjoin("/", command);
		path = ft_strjoin(paths[i], temp);
		free(temp);
		if (access(path, X_OK) == 0)
			return (path);
		++i;
		// ft_free_str(path);
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != 0)
	{
		i++;
		cnt++;
	}
	return (cnt);
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
