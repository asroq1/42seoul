
#include <stdio.h>

int main(void)
{
	int i, j, k, n;
	
	printf("input some number here...");
	printf("\n");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		for (k = 1; k < n - i; k++)
		{
			if (k == (n - i - 1))
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}			
		}
		printf("\n");
	}
}