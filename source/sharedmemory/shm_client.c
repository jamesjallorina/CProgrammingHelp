#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>


#define mailbox_key 1432
#define MAXLEN 4024

int mailbox_locate(const key_t key);
struct sharedmsg *mailbox_attach(const int shmid);

struct sharedmsg{
	unsigned int forcednumber;
	char msg[MAXLEN + 1];
};

#define SHAREDMSG_SZ sizeof(struct sharedmsg)

struct mailbox{
	int shmid;
	char *msg;
	struct sharedmsg *data;   //pass 4kb of data
};


int main(int argc, char **argv)
{
	
	char c;
	struct mailbox mb;
	struct mailbox *p = &mb;
	struct sharedmsg *msg;

	p->shmid = mailbox_locate(mailbox_key);
	msg = mailbox_attach(p->shmid);
	
	
       	printf("read from sharedmemory | forcednumber: %d\n", msg->forcednumber);
	printf("read from shared memory | msg: %s\n", msg->msg);	
	return 0;	
}


int mailbox_locate(const key_t key)
{
	int shmid = 0;

	if((shmid =shmget(key, SHAREDMSG_SZ, 0666)) <  0){
		perror("shmget");
		exit(1);
	}
	return shmid;
}


struct sharedmsg *mailbox_attach(const int shmid)
{
	static struct sharedmsg *shm;

	if((shm = (struct sharedmsg *)shmat(shmid, NULL, 0)) == (struct sharedmsg *) -1){
		perror("shmat");
		exit(1);
	}
	return shm;
}
