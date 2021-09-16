#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		i++;
		cnt++;
	}
	return cnt;
	
}