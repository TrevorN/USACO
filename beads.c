/*
ID: trevor.1
LANG: C
TASK: beads
*/
#include "stdio.h"

int beadEquals(char a, char b)
{
	if(a == b)
	{
		return 1;
	}

	return 0;
}

int laxBeadEquals(char a, char b)
{
	if(a == b)
	{
		return 1;
	}

	if(a == 'w' || b == 'w') {
		return 1;
	}

	return 0;
}

// int diffNotW(char a, char b)
// {
// 	if((a == 'r' && b == 'b') || (a == 'b' && b == 'r'))
// 	{
// 		return 1;
// 	}

// 	return 0;
// }

int countLeft(int start, char necklace[], int length)
{
	int res = 1;

	int count = start + length - 1;

	while(laxBeadEquals(necklace[start], necklace[count % length]) == 1)
	{
		if(necklace[start] == 'w' && necklace[count % length] != 'w')
		{
			start = count % length;
		}
		res++;
		count--;
	}
	return res;
}

int countRight(int start, char necklace[], int length)
{
	int res = 1;

	int count = (start + 1) % length;

	while(laxBeadEquals(necklace[start], necklace[count % length]) == 1)
	{
		if(necklace[start] == 'w' && necklace[count % length] != 'w')
		{
			start = count % length;
		}
		res++;
		count++;
	}

	return res;
}

int main()
{
	FILE *in = fopen("beads.in", "r");
	FILE *out = fopen("beads.out", "w");

	int numBeads;

	fscanf(in, "%d", &numBeads);

	char necklace [numBeads];

	fscanf(in, "%s", necklace);

	fclose(in);

	int breakpoint = 0;

	int longest = 0;

	int i;

	for(i = 0; i < numBeads; i++)
	{
		if(beadEquals(necklace[i], necklace[(i + 1) % numBeads]) == 0)
		{
			//This here code shall only be execued when a split has been recognized.
			int left = countLeft(i, necklace, numBeads);
			int right = countRight(i + 1, necklace, numBeads);

			if(left + right > longest)
			{
				longest = left + right;
				printf("%d\n", left);
				printf("%d\n", right);
			}
		}
	}


	if(longest == 0)
	{
		fprintf(out, "%d\n", numBeads);
	} else {
		fprintf(out, "%u\n", longest);
	}

	fclose(out);

	return 0;
}