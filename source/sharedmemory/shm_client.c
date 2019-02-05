#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>


#define SHMSZ 27
#define mailbox_key 1432

int mailbox_locate(const key_t key);
char *mailbox_attach(const int shmid);


struct mailbox{
	int shmid;
	char *msg;
	char sharedmsg[4024 + 1];   //pass 4kb of data
};



int main(int argc, char **argv)
{
	char c;
	struct mailbox mb;
	struct mailbox *p = &mb;

	p->shmid = mailbox_locate(mailbox_key);
	p->msg = mailbox_attach(p->shmid);

	for(;*(p->msg) != '\0'; p->msg++)
		putchar(*(p->msg));
	putchar('\n');
	*(p->msg) = '*';
	return 0;	
}


int mailbox_locate(const key_t key)
{
	int shmid = 0;

	if((shmid =shmget(key, SHMSZ, 0666)) <  0){
		perror("shmget");
		exit(1);
	}
	return shmid;
}


char *mailbox_attach(const int shmid)
{
	char *shm;

	if((shm = shmat(shmid, NULL, 0)) == (char *) -1){
		perror("shmat");
		exit(1);
	}
	return shm;
}
