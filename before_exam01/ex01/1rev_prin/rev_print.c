#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	int i = 0;
	int cnt = 0;

	if (argc == 2)
	{
		/* code */
			while (argv[1][i] != '\0')
	{
		i++;
		cnt++;
	}
	while (cnt)
	{
		write(1, &argv[1][cnt-1], 1);
		cnt--;
	}	
	write(1, "\n", 1);
	}
}