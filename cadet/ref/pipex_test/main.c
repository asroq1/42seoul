# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

// int	ft_strlen(const char *str)
// {
// 	size_t	i;
// 	size_t	cnt;

// 	i = 0;
// 	cnt = 0;
// 	while (str[i] != 0)
// 	{
// 		i++;
// 		cnt++;
// 	}
// 	return (cnt);
// }

// char	*ft_substr(char const *s, int start, int len)
// {
// 	char			*new_str;
// 	int				i;
// 	int				j;

// 	i = start;
// 	j = 0;
// 	if (s == 0)
// 		return (0);
// 	new_str = malloc(sizeof(char) * (len + 1));
// 	if (new_str == 0)
// 		return (0);
// 	if (start >= ft_strlen(s))
// 	{
// 		new_str[0] = 0;
// 		return (new_str);
// 	}
// 	while (j < len && s != 0)
// 	{
// 		new_str[j] = s[i];
// 		i++;
// 		j++;
// 	}
// 	new_str[j] = 0;
// 	return (new_str);
// }

// static char	**do_split(char **new_str, char const *s, char c, int count)
// {
// 	int	i;
// 	int	j;
// 	int	next;

// 	i = 0;
// 	j = 0;
// 	while (s[i] != 0 && j < count)
// 	{
// 		if (s[i] != c)
// 		{
// 			next = i + 1;
// 			while (s[next] != 0 && s[next] != c)
// 				next++;
// 			new_str[j] = ft_substr(s, i, next - i);
// 			// if (new_str[j] == 0)
// 			// 	return (ft_free(new_str));
// 			j++;
// 			i = next;
// 		}
// 		else
// 			i++;
// 	}
// 	new_str[j] = 0;
// 	return (new_str);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**new_str;
// 	int		word_count;
// 	int		i;

// 	if (s == 0)
// 		return (0);
// 	i = 0;
// 	word_count = 0;
// 	while (s[i] != 0)
// 	{
// 		if (s[i] != c)
// 		{
// 			word_count++;
// 			while ((s[i] != c) && s[i] != 0)
// 				i++;
// 		}
// 		else
// 			i++;
// 	}
// 	new_str = malloc(sizeof(char *) * (word_count + 1));
// 	if (new_str == 0)
// 		return (0);
// 	do_split(new_str, s, c, word_count);
// 	return (new_str);
// }

// char	*ft_strnstr(const char *str, const char *substr, int n)
// {
// 	int			i;
// 	int			j;

// 	i = 0;
// 	if (*substr == 0)
// 	{
// 		return ((char *)str);
// 	}
// 	while (str[i] != 0 && i < n)
// 	{
// 		j = 0;
// 		while (str[i + j] == substr[j] && i + j < n)
// 		{
// 			j++;
// 			if (substr[j] == 0)
// 			{
// 				return ((char *)&str[i]);
// 			}
// 		}	
// 		i++;
// 	}
// 	return (0);
// }
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new_str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	if (s1 == 0 || s2 == 0)
// 		return (0);
// 	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (new_str == 0)
// 		return (0);
// 	while (i < ft_strlen(s1))
// 	{
// 		new_str[i] = s1[i];
// 		j = 0;
// 		i++;
// 	}
// 	while (j <= ft_strlen(s2))
// 	{
// 		new_str[i] = s2[j];
// 		j++;
// 		i++;
// 	}
// 	return (new_str);
// }

// char	*get_path(char *command, char **envp)
// {
// 	char	**paths;
// 	char	*path;
// 	char	*temp;
// 	int		i;

// 	i = 0;
// 	while (ft_strnstr(envp[i], "PATH", 6) == 0)
// 		++i;
// 	paths = ft_split(envp[i] + 5, ':');
// 	if (paths == 0)
// 		printf("doesn't exist paths...\n");
// 	i = 0;
// 	while (paths[i] != 0)
// 	{
// 		temp = ft_strjoin("/", command);
// 		path = ft_strjoin(paths[i], temp);
// 		free(temp);
// 		if (access(path, X_OK) == 0)
// 			return (path);
// 		++i;
// 		// ft_free_str(path);
// 	}
// 	return (0);
// }

// void	execute(char *argv, char **envp)
// {
// 	char	**command;
// 	char	*path;
// 	int 	i;
// 	command = ft_split(argv, ' ');
// 	printf("command argv => %c\n", command);
// 	printf("command argv => %c\n", *command[1]);

// 	path = get_path(command[0], envp);
// 	printf("path ==> %s\n", path);
// 	if (command == 0)
// 	{
// 		// error();
// 	}
// 	printf("execve : path=%s command=%s envp=%s\n", path, command, envp);
// 	if (execve(path, command, envp) == -1)
// 	{
// 		// error();
// 	}
// }

int main(int argc, char **argv, char **envp)
{
	// execute(argv[2], envp);
	char *arr[] = {"ls", "-al",  NULL};
	int returnv = execve("/bin/ls", arr, envp);
	// printf("value = %d\n", returnv);
}
