#include <stdio.h>
#include <unistd.h>

int main(int argc, char **agrv)
{
	int i;
	i = 0;

	if (argc == 2)
	{
		while (agrv[1][i] != '\0')
	{
		if (agrv[1][i] >= 'a' && agrv[1][i] <= 'm')
		{
			agrv[1][i] += 13;
		}
		else if(agrv[1][i] >= 'n' && agrv[1][i] <= 'z')
		{ 
			agrv[1][i] -= 13;

		}
		else if (agrv[1][i] >= 'A' && agrv[1][i] <= 'M')
		{
			agrv[1][i] += 13;
			
		}
		else if(agrv[1][i] >=  'N' && agrv[1][i] <= 'Z')
		{ 
			agrv[1][i] -= 13;
		}
		write(1, &agrv[1][i], 1);
		i++;
	}
	}
	write(1, "\n", 1);

}