#include "utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 65536

int countlines(FILE *file)
{
	char buf[BUF_SIZE];
	int count = 0;

	// read BUF_SIZE chars
	// from the file until EOF
	while (!feof(file))
	{
		size_t numChars = fread(&buf, 1, BUF_SIZE, file);

		// count '\n' characters
		for (size_t i = 0; i < numChars; ++i)
		{
			if (buf[i] == '\n')
			{
				count += 1;
			}
		}
	}

	// reset file position indicator and clear EOF indicator
	rewind(file);

	return count;
}

char **getlines(FILE *file, int count)
{
	char **lines = malloc(count * sizeof(char *)); 	// array of lines

	char *lineptr = NULL; // address of buffer containing line text
	size_t n = 0; // size of buffer

	for (int i = 0; i < count; ++i)
	{
		ssize_t numChars = getline(&lineptr, &n, file); // read line

		if (numChars != -1)
		{ // succesful read of a line
			// read addr of buffer containing line text into lines array
			lines[i] = lineptr;
		}
		else
		{
			free(lineptr);
		}
		lineptr = NULL;
	}

	return lines;
}
