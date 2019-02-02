#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void concat(const char *orig, const char *add, char *res)
{
	const size_t ol = strlen(orig);
	const size_t al = strlen(add);

	memcpy(res, orig, ol);
	memcpy(&res[ol], add, al);
	return;
}	

int main(int argc, char **argv)
{
	char origstr[] = "hello";
	char addstr[] = "world";
	char container[10 + 1];

	memset(container, 0, sizeof(container));

	concat(origstr, addstr, container);
	printf("%s \n", container);

	return 0;
}
