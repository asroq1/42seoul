#include <unistd.h>

int main()
{

	char upp = 'B';
	char odd = 'a';

	while (upp <= 'Z')
	{
		write(1, &odd, 1);
		write(1, &upp, 1);
		upp +=2;
		odd +=2;
	}
	write(1, '\0', 1);
}