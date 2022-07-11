#include <unistd.h>

int	main(int argc, char **argv)
{
	int used[255] = {0,};
	int	i = 0;
	int	j = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (used[(int)argv[1][i]] == 0 && argv[1][i] == argv[2][j])
				{
					write (1, &argv[1][i], 1);
					used[(int)argv[1][i]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
