#include <stdio.h>
void	ft_swap(int *a, int *b)
{
	int temp; 
	temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;

}

int main()
{
	int a = 5;
	int b = 1;
	ft_swap(&a, &b);
	printf("a : %d b : %d", a, b);

}