#include <unistd.h>
#include <stdint.h>
int main(int argv, char **argc)
{	
	int i = 0;
	int cnt = 0;
	if(argv == 2)
	{
	    while (argc[1][i] != '\0')
		{
			if (argc[1][i] == 'a')
			{
				write(1, "a", 1);	
				write(1, "\n", 1);
				return 0;
			}
			else
			{
				cnt = 1;
			}
		 	i++;
		}
	}
	else
	{
		write(1, "a", 1);	
	}
	if (cnt > 0)
	{
		write(1, "\n", 1);
	}
	
	return 0;
}

