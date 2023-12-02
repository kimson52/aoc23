#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>
#include <stdio.h>

// Counts number of lines of the given file
// assumes single-byte character encoding
int countlines(FILE *file);

// Read all lines of a file and return an
// array containing the read lines of the file
// it is the responsibility of the caller to
// deallocate the array and its contents
char **getlines(FILE *file, int count);

#endif
