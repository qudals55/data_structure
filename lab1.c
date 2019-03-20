#include <stdio.h>
#include <stdlib.h>
#define DATAFILE "lab1.dat"

int main (int argc, char* argv[])
{
	char arr[10000];
	FILE* fp = NULL;
	int index, count;
	fp = fopen(DATAFILE, "r");
	while(~fscanf(fp, "%s", arr))
	{
		printf("%s\n", arr);
		index=0;
		count=0;
		while(arr[index] != '\0')
		{
			if(arr[index++] == ' ')
				count++;
		}
		printf("The number of Words : %d\n", count+1);
	}
	return 0;
}
