/*
ID: trevor.1
LANG: C
TASK: transform
*/
#include <stdio.h>

int length;

void ninety(char *toChange)
{
	char newArr[length * length];

	int i = 0;

	while(i < length * length)
	{
		newArr[i] = toChange[((length * (length - 1)) + (i / length)) - (length * (i % length))];
		i++;
	}

	toChange = newArr;
}

void reflect(char *toChange)
{
	char newArr[length * length];

	int i = 0;

	while(i < length * length)
	{
		newArr[i] = toChange[(length * (i / length)) + (length - (i % length))];
		i++;
	}

	toChange = newArr;
}

int match(char *one, char *two)
{
	int i = 0;

	while(i < length * length)
	{
		if(one[i] != two[i])
		{
			return 0;
		}

		i++;
	}

	return 1;
}

int main()
{
	FILE *in = fopen("transform.in", "r");
	FILE *out = fopen("transform.out", "w");

	fscanf(in, "%d", &length);

	char orig[length * length];

	char trans[length * length];

	int i = 0;

	while(i < length * length)
	{
		fscanf(in, "%c", &orig[i]);
		i++;
	}

	i = 0;

	while(i < length * length)
	{
		fscanf(in, "%c", &trans[i]);
		i++;
	}

	i = 0;

	while(i < length * length)
	{
		printf("%c", orig[i]);
		if(i % length == 0)
		{
			printf("\n");
		}

		i++;
	}

	fclose(in);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d", 6);
		fclose(out);
		return 0;
	}

	ninety(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d", 1);
		fclose(out);
		return 0;
	}

	ninety(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d", 2);
		fclose(out);
		return 0;
	}

	ninety(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d", 3);
		fclose(out);
		return 0;
	}

	ninety(orig);

	reflect(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d", 4);
		fclose(out);
		return 0;
	}

	ninety(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d", 4);
		fclose(out);
		return 0;
	}

	ninety(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d", 4);
		fclose(out);
		return 0;
	}
	
	ninety(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d", 4);
		fclose(out);
		return 0;
	}

	fprintf(out, "%d", 7);
	fclose(out);
	return 0;
}
