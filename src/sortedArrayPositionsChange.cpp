/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i, j, x, temp, count = 0, index1 = 0, index2 = 0;
	if (Arr == NULL || len < 0) return NULL;
	for (i = 0, j = 1; j<len; i++, j++)
	{
		if (Arr[i]>Arr[j])
		{
			if (count == 0)
			{
				index1 = i;
				x = j;
				count++;
			}
			else
			{
				index2 = j;
				count++;
			}
		}
	}
	if (count == 1)
	{
		temp = Arr[index1];
		Arr[index1] = Arr[x];
		Arr[x] = temp;
	}
	else
	{
		temp = Arr[index1];
		Arr[index1] = Arr[index2];
		Arr[index2] = temp;
	}
	count = 0;
	for (i = 0, j = 1; j<len; i++, j++)
	{
		if (Arr[i]>Arr[j])
			count++;
	}
	if (count == 0)
		return Arr;
	else
		sortedArrayPositionsChange(Arr, len);
}