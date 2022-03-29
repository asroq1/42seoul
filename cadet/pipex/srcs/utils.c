/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:57:55 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/29 12:11:17 by hyunjung         ###   ########.fr       */
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
	//1. strnstr을 통해서 환경변수에 PATH 문자열을 찾을 때까지 i++
	while (ft_strnstr(envp[i], "PATH", 6) == 0)
		++i;
	// 2.envp[i] + 5를 통해서 앞의 PATH=부분을 넘기고 :를 만나면 문자열을 잘라 paths에 담는다
	paths = ft_split(envp[i] + 5, ':');
	if (paths == 0)
		error();
	i = 0;
	while (paths[i] != 0)
	{
		// 3. 명령어 앞에 /를 붙여준다
		temp = ft_strjoin("/", command);
		// 4. 경로인 paths 끝에 temp를 붙여준다.
		path = ft_strjoin(paths[i], temp);
		free(temp);
		// 5. 만약 path가 올바른 경로라면 접근한다.
		if (access(path, X_OK) == 0)
			return (path);
		++i;
		//leaks을 방지하기 위해 malloc 한 것들을 다 free한다.
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
