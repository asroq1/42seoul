#include <stdio.h>
void	ft_putstr(char *str);


int		main(void)
{
	char *str;

	str = "Hello World";
	printf("string is \"%s\"\n",str);
	ft_putstr(str);
	printf("\n");
}