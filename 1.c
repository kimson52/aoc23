#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstAndLast(const char *str);
int isNumber(char c);

int main(int argc, char **argv)
{
	// store sum
	int sum = 0;

	// open file
	FILE *file = fopen(argv[1], "r");

	// get lines of file
	int numLines = countlines(file);
	char **lines = getlines(file, numLines);

	// loop through each line
	// find the first and last number in the line
	// put them together and turn it into an int
	for (int i = 0; i < numLines; ++i)
	{
		int num = firstAndLast(lines[i]);
		sum += num;
	}

	printf("Sum: %d\n", sum);

	// deallocate memory
	for (int i = 0; i < numLines; ++i)
	{
		free(lines[i]);
	}
	free(lines);
	fclose(file);

	return 0;
}

int firstAndLast(const char *str)
{
	char nums[3];
	int num;

	// loop through each character from beginning
	int i = 0;
	while (!isNumber(str[i]))
	{
		++i;
	}
	nums[0] = str[i];

	// loop through each character from end
	i = strlen(str) - 1;
	while (!isNumber(str[i]))
	{
		--i;
	}
	nums[1] = str[i];

	nums[2] = '\0'; // null terminate!!!

	num = atoi(nums);
	return num;
}

int isNumber(char c)
{
	return c >= 48 && c <= 57;
}
