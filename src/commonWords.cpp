/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31


void stringcopy(char *src, int start, int end, char **temp);
int strfind(char *key, int begin, int end, char *src);


char ** commonWords(char *str1, char *str2) 
{
	int i = 0, previous = 0, size = 1;
	char **res = NULL; char *copy = NULL;
	if (str1 == NULL || str2 == NULL) 
	{
		return NULL;
	}



	while (str1[i] != '\0') 
	{
		if (str1[i] == ' ' && i != 0 && str1[i - 1] != ' ') 
		{
			if (strfind(str1, previous, i - 1, str2)) 
			{
				stringcopy(str1, previous, i - 1, &copy);
				res = (char **)realloc(res, sizeof(char *) * size);
				res[size - 1] = copy;
				size++;
			}
			previous = i + 1;
		}

		i++;
	}
	if (previous != 0) 
	{
		if (strfind(str1, previous, i - 1, str2)) 
		{
			stringcopy(str1, previous, i - 1, &copy);
			res = (char **)realloc(res, sizeof(char *)* size);
			res[size - 1] = copy;
		}
	}
	return res;
}


void stringcopy(char *src, int start, int end, char **temp) 
{
	int i; char *final_array;
	final_array = (char *)malloc(sizeof(char)* (end - start + 2));
	for (i = start; i <= end; i++) 
	{
		final_array[i - start] = src[i];
	}
	final_array[i - start] = '\0';
	*temp = final_array;
	return;
}

int strfind(char *key, int begin, int end, char *src) 
{
	int i = 0, j = begin;
	while (src[i] != '\0') 
	{
		if (j > end) 
		{
			if (src[i] == ' ' || src[i] == '\0') 
			{
				return 1;
			}
			j = begin;
		}
		else if (src[i] == key[j]) 
		{
			j++;
		}
		else 
		{
			j = begin;
		}
		i++;
	}
	if (j > end) 
		return 1;
	return 0;
}
