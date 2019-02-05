#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>


#define SHMSZ 27
#define mailbox_key 1432

int mailbox_create(const key_t key);
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

	p->shmid = mailbox_create(mailbox_key);
	p->msg = mailbox_attach(p->shmid);
	

	for(c = 'a'; c <= 'z'; c++)
		*(p->msg++) = c;
	*(p->msg) = '\0';

	while(*(p->msg) != '*')
		sleep(1);

	return 0;
}



int mailbox_create(const key_t key)
{
	int shmid = 0;
	/*
	 * create segment
	 */
	if((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666 )) < 0){
		perror("shmat");
		exit(1);
	}
	return shmid;
}

char *mailbox_attach(const int shmid)
{
	char *shm;
	
	if((shm = shmat(shmid,NULL, 0)) == (char *) -1){
		perror("shmat");
		exit(1);
	}
	return shm;
}


