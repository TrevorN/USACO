/*
ID: trevor.1
LANG: C
TASK: milk2
*/
#include <stdio.h>

void order(int *arr, int size)
{
	int final[size];

	int i = 0;

	while(i < size)
	{
		int smallest = 0;

		int index = 0;

		while(arr[index] == -1 && index < size)
		{
			index++;
		}

		smallest = index;

		while(index < size)
		{
			if(arr[index] < arr[smallest] && arr[index] != -1)
			{
				smallest = index;
			}
			index++;
		}

		final[i] = arr[smallest];
		arr[smallest] = -1;
		i++;
	}

	i = 0;

	while(i < size)
	{
		arr[i] = final[i];
		i++;
	}
}

int main()
{
	FILE *in = fopen("milk2.in", "r");
	FILE *out = fopen("milk2.out", "w");

	int numFarmers;

	fscanf(in, "%d", &numFarmers);

	int startTimes[numFarmers];

	int endTimes[numFarmers];

	int i = 0;

	while(i < numFarmers)
	{
		int store;
		fscanf(in, "%d", &store);
		startTimes[i] = store;
		fscanf(in, "%d", &store);
		endTimes[i] = store;
		i++;
	}

	order(startTimes, numFarmers);

	order(endTimes, numFarmers);

	i = 0;

	// while(i < numFarmers)
	// {
	// 	printf("%d\t%d\n", startTimes[i], endTimes[i]);
	// 	i++;
	// }

	/*
		The input has been properly recieved and sorted,
	now it is time to process it!
	*/

	int startI = 0;
	int endI = 0;
	int currentWorking = 0;
	int sessionStart = 0;
	int sessionEnd = startTimes[1];
	int longestWith = 0;
	int longestWithout = -1;

	while(startI <= numFarmers && endI < numFarmers)
	{

		// if(true)
		// {

		// 	printf("%d\t%d\n", startI, endI);

		// 	i = 0;

		// 	while(i < numFarmers)
		// 	{
		// 		int start = startTimes[i];
		// 		int end = endTimes[i];

		// 		if(i < startI)
		// 			start = 0;

		// 		if(i < endI)
		// 			end = 0;

		// 		printf("%d\t%d\n", start, end);

		// 		i++;
		// 	}
		// 	printf("\n");
		// }	

		// printf("%d\t%d\t%d\n\n", currentWorking, longestWith, longestWithout);

		if(startTimes[startI] <= endTimes[endI] && startI < numFarmers)
		{

			currentWorking++;

			if(longestWithout == -1)
			{
				longestWithout = 0;
			}

			if(currentWorking == 1)
			{
				if(startTimes[startI] - sessionEnd > longestWithout)
				{
					longestWithout = startTimes[startI] - sessionEnd;
				}

				sessionStart = startTimes[startI];
			}

			startI++;

		} else {

			currentWorking--;

			if(currentWorking == 0)
			{
				if(endTimes[endI] - sessionStart > longestWith)
				{
					longestWith = endTimes[endI] - sessionStart;
				}

				sessionEnd = endTimes[endI];
			}

			endI++;
		}

	}

	printf("%d\t%d\t%d\n", currentWorking, longestWith, longestWithout);

	fprintf(out, "%d %d\n", longestWith, longestWithout);

	return 0;

}