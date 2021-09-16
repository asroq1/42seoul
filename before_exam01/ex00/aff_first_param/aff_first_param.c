#include <unistd.h>

int main(int argv, char **argc)
{
	int i;
	i = 0;

	if(argv > 1)
	{
		while (argc[1][i] != '\0')
		{
			write(1, &argc[1][i] , 1);
			if (argc[1][i] == '\0')
			{
				write(1, "\n", 1);
			}
		i++;	
		}
	}
	else
	{
		write(1, "\n", 1);
	}
	return 0;
}