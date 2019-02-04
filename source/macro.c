#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

	return 0;
}
