/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<string.h>
char removeSpaces(char *str) {
	if (str == NULL || str == "")
		return '\0';
	int l = strlen(str);
	int i = 0, j = 0, k;
	j = i;
	while (str[i] != '\0')
	{
		
		if (str[i] != ' ')
			i++;
		else
		{
			j = i;
			k = i;
			while (str[j] == ' ')
				j++;
			for (; j <= strlen(str); j++)
			{
				str[k] = str[j];
				k++;
			}
		}

	}

}