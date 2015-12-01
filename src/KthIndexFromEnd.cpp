/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<string.h>
char KthIndexFromEnd(char *str, int K) {
	int l = 0;
	if (str == NULL||str=="")
		return '\0';
	while (str[l] != '\0')
		l++;
	if (str != "" || K < l || K>0)
	{
		return str[l - K - 1];
	}
	else
		return '\0';
}