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

	i = 0;

	while(i < length * length)
	{
		toChange[i] = newArr[i];
		i++;
	}
}

void reflect(char *toChange)
{
	char newArr[length * length];

	int i = 0;

	while(i < length * length)
	{
		newArr[i] = toChange[(length * ((i / length) + 1)) - (i % length) - 1];
		i++;
	}

	i = 0;

	while(i < length * length)
	{
		toChange[i] = newArr[i];
		i++;
	}
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
		if(orig[i] != '\n')
		{
			i++;
		}
	}

	i = 0;

	while(i < length * length)
	{
		fscanf(in, "%c", &trans[i]);
		if(trans[i] != '\n')
		{
			i++;
		}
	}

	fclose(in);

//Done parsing input!

	int flag = 0;

	if(match(orig, trans) == 1)
		flag = 1;

	ninety(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d\n", 1);
		fclose(out);
		return 0;
	}

	ninety(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d\n", 2);
		fclose(out);
		return 0;
	}

	ninety(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d\n", 3);
		fclose(out);
		return 0;
	}

	ninety(orig);

	reflect(orig);

	i = 0;

	while(i < length * length)
	{
		printf("%c",orig[i]);
		i++;
		if(i % length == 0)
			printf("\n");
	}

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d\n", 4);
		fclose(out);
		return 0;
	}

	ninety(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d\n", 5);
		fclose(out);
		return 0;
	}

	ninety(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d\n", 5);
		fclose(out);
		return 0;
	}
	
	ninety(orig);

	if(match(orig, trans) == 1)
	{
		fprintf(out, "%d\n", 5);
		fclose(out);
		return 0;
	}

	if(flag == 1)
	{
		fprintf(out, "%d\n", 6);
		fclose(out);
		return 0;
	}

	fprintf(out, "%d\n", 7);
	fclose(out);
	return 0;
}
