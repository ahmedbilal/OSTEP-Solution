#include <stdio.h>
#include <stdlib.h>

int main()
{
	int * array = (int *) malloc(100 * sizeof(int));
	free(array);

	for (int i = 0; i < 100; i++)
	{
		printf("%d\n", array[i]);
	}
}
