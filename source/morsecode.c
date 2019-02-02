#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RESET 0

struct morsecode
{
	unsigned int block;
	unsigned char code;
};
char mapcode(const unsigned short block);
void morsecode(const char *morsecode);

struct morsecode codeblock[26] =
{
	{1, 'A'},
	{2, 'B'},
	{3, 'C'},
	{4, 'D'},
	{5, 'E'},
	{6, 'F'},
	{7, 'G'}, 
	{8, 'H'},
	{9, 'I'},
	{10,'J'},
	{11,'K'},
	{12,'L'},
	{13,'M'},
	{14,'N'},
	{15,'O'},
	{16,'P'},
	{17,'Q'},
	{18,'R'},
	{19,'S'},
	{20,'T'},
	{21,'U'},
	{22,'V'},
	{23,'W'},
	{24,'X'},
	{25,'Y'},
	{26,'Z'}
};


char mapcode(const unsigned short block)
{
	if(block > 25)
		exit(1);

	for(int pos = 0; pos <= block; pos++) 
	{
		if( codeblock[pos].block  == block)
			return codeblock[pos].code;
	}
}

void morsecode(const char *morsecode)
{
	int counter = 0;
	int moved = 0;
	const int boundchk = strlen(morsecode); 

	for(int pos = 0; pos <= boundchk; pos++)
	{
		if( memcmp(&morsecode[pos],"_",sizeof(char)) == 0)
			counter++;
		if( memcmp(&morsecode[pos], ",", sizeof(char)) == 0)
		{
			printf("%c ", mapcode(counter));
		       	counter = RESET;	
		}
		moved = pos;
	}		
	printf("%c ", mapcode(counter));
	printf("\n");
#if defined(_DEBUG_)
	printf("total positions moved: %d \n", moved); 
#endif
	printf("\n");		
	return;
}


int main(int argc, char **argv)
{
	if(argc < 1)
		exit(0);
#if defined(_DEBUG_)
	printf("number of characters: %d \n",(int) strlen(argv[1]));	
#endif
	morsecode(argv[1]);

	return 0;
}
