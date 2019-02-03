#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>

#define SAFE_TXT "safe_"
#define SPAM_TXT "spam_"
#define path "/home/skye/repository/CProgrammingHelp/source"
#define _DEBUG_

int access_safe_txt();
int access_spam_txt();
int num_of_files(const char *);

static unsigned int total_safe_txt;
static unsigned int total_spam_txt;

int main(int argc, char **argv)
{
	
#if defined(_DEBUG_)
	
	total_safe_txt  = num_of_files(SAFE_TXT);
	printf("total number of safe_ files: %d\n", total_safe_txt);
	total_spam_txt = num_of_files(SPAM_TXT);
	printf("total number of spam_ files: %d\n", total_spam_txt);
	access_safe_txt();
	access_spam_txt();	
#endif	
	return 0;

}

int access_safe_txt()
{
	FILE *fp = NULL;	
	char filename[20 + 1];
	char buffer[250 +1];
	unsigned int counter = 1 ;
	
	memset(filename, 0, sizeof(filename));
	memset(buffer, 0, sizeof(buffer));

	for(int i=0; i<total_safe_txt; i++)
	{
		sprintf(filename, "%s%d.txt", SAFE_TXT, counter++);
	 	fp = fopen(filename, "r");
		fscanf(fp, "%s", buffer);
	        printf("content has: |%s|\n", buffer);	
		//do whatever else you want
		fclose(fp);
		fp = NULL;
	}
	return 0;
}

int access_spam_txt()
{
	FILE *fp = NULL;	
	char filename[20 + 1];
	char buffer[250 +1];
	unsigned int counter = 1 ;
	
	memset(filename, 0, sizeof(filename));
	memset(buffer, 0, sizeof(buffer));

	for(int i=0; i<total_safe_txt; i++)
	{
		sprintf(filename, "%s%d.txt", SPAM_TXT, counter++);
	 	fp = fopen(filename, "r");
		fscanf(fp, "%s", buffer);
	        printf("content has: |%s|\n", buffer);	
		//do whatever else you want
		fclose(fp);
		fp = NULL;
	}

	return 0;
}

int num_of_files(const char *name)
{
	int files = 0;
	int i = 1;
	DIR *dirp;
	struct dirent *entry;

#if defined(_DEBUG_)
	printf("opening path: %s\n", path);
#endif
	dirp = opendir(path);
	while (dirp){
		errno = 0;
		if((entry = readdir(dirp)) != NULL) {
#if defined(_DEBUG_)
			printf("files inside: %s\n", entry->d_name);
#endif
			if( memcmp(entry->d_name, name, 5) == 0)	
			{
				files++;
#if defined(_DEBUG_)
				printf("counter: %d\n", files);
#endif
			}
		}
		else
		{
			break;
		}
#if defined(_SLEEP_MODE_)
		sleep(1);
#endif
	}
	closedir(dirp);
	return files;
}
