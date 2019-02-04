#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOOP 4
#define safetxt(decimal) "safe_" #decimal ".txt"
#define spamtxt(decimal) "spam_" #decimal ".txt"


int main(int argc, char **argv)
{
	printf("%s\n", safetxt(1));
	printf("%s\n", safetxt(2));
	printf("%s\n", safetxt(3));
	printf("%s\n", spamtxt(1));
	printf("%s\n", spamtxt(2));
	printf("%s\n", spamtxt(3));

	//if you want to pass a variable to a macro then there's no way it will evaluate to a decimal value
	//instead use a switch case
	for(int i=0, counter=1; i<MAX_LOOP; i++, counter++)
	{
		switch(counter)
		{
			case 1:
			printf("%s\n", safetxt(1));
			printf("%s\n", spamtxt(1));
			break;
			case 2:
			printf("%s\n", safetxt(2));
			printf("%s\n", spamtxt(2));
			break;
			case 3:
			printf("%s\n", safetxt(3));
			printf("%s\n", spamtxt(3));
			break;
			default: break;
		}
	}
	return 0;
}
