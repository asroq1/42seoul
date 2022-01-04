char	*ft_read(int fd, char *save)
{
	char		*buff;
	ssize_t		return_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	return_bytes = 1;
	while (!ft_strchr(save, '\n') && return_bytes != 0)
	{
		return_bytes = read(fd, buff, BUFFER_SIZE);
		if (return_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[return_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

int	main(void)
{
	char	*str;
	ft_read();
}
