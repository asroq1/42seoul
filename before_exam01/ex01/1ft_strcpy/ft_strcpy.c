#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int i;
	i = 0;
	while (s1[i] != '\0')
	{
		s1[i] = s2[i];
		i++;	
		printf("%c", s1[i]);
	}
	s1[i] = '\0';
	return s1;
}
