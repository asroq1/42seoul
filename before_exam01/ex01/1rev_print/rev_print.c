#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int cnt = 0;

	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			cnt = argv[1][i] - 64;
			while (cnt == 0)
			{
				write(1,&argv[1][i],1);
				cnt--;
			}
		}
		else if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			cnt = argv[1][i] - 96;
			while (cnt == 0)
			{
				write(1,&argv[1][i],1);
				cnt--;
			}
		}
	i++;	
	}
}