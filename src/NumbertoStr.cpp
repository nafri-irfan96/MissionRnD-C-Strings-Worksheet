/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>


void number_to_str(float number, char *str,int afterdecimal){
	int temp, i = 0;

	*str = NULL;
	if (afterdecimal == 0)
	{
		temp = (int)number;
		temp = (temp < 0) ? -temp : temp;

		while (temp != 0)
		{
			str[i] = temp % 10 + '0';
			temp /= 10;
			i++;
		}
		str[i] = '\0';
		strrev(str);
		if (number < 0)
		{
			for (i = strlen(str); i >= 1; i--)
			{
				str[i] = str[i - 1];
			}
			str[strlen(str) + 1] = '\0';
			str[0] = '-';
		}
	}
	if (afterdecimal != 0)
	{
		temp = (int)number;
		temp = (temp < 0) ? -temp : temp;
		int mul = 1;
		i = 0;
		while (temp != 0)
		{
			str[i] = temp % 10 + '0';
			temp /= 10;
			i++;
		}
		str[i] = '\0';
		strrev(str);
		str[i] = '.';
		str[i + 1] = '\0';


		char *t;
		t = (char*)malloc((afterdecimal)*sizeof(char));
		float temp2;
		temp2 = number - (int)number;
		while (afterdecimal != 0)
		{
			mul *= 10;
			afterdecimal--;
		}
		temp2 *= mul;
		int stringadder = (int)temp2;
		stringadder = stringadder < 0 ? -stringadder : stringadder;
		i = 0;
		while (stringadder != 0)
		{
			t[i] = stringadder % 10 + '0';
			stringadder /= 10;
			i++;
		}
		t[i] = '\0';
		strrev(t);
		strcat(str, t);

		if (number < 0)
		{
			for (i = strlen(str); i >= 1; i--)
			{
				str[i] = str[i - 1];
			}
			str[strlen(str)] = '\0';
			str[0] = '-';
		}
	}
}
