#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>


#define SHMSZ 27
#define mailbox_key 1432
#define MAXLEN 4024

int mailbox_create(const key_t );
char *mailbox_attach(const int );
struct sharedmsg *build_message(const unsigned int, const char *, size_t );
void write_to_mailbox();
void usage();

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

struct mailbox mb;

int main(int argc, char **argv)
{
	//char c;
	unsigned int currmsglen = 0;
	unsigned int forcednumber = 0;
	struct mailbox *p = &mb;
	
	if(argc < 1)
	{
		usage();
		exit(1);
	}
	currmsglen = strlen(argv[2]);
	forcednumber = atoi(argv[1]);
	printf("forcednumber: %d\n", forcednumber);
	printf("msg: %s\n", argv[2]);
	printf("currmsglen: %d\n", currmsglen);

	p->shmid = mailbox_create(mailbox_key);
	p->msg = mailbox_attach(p->shmid);
	p->data = build_message(forcednumber, argv[2], currmsglen);
	write_to_mailbox();	

	while(1)
	 sleep(1);

	return 0;
}

void usage()
{
	fprintf(stderr, "shm_server <forcednumber> <msg>");
	return;
}

void write_to_mailbox()
{
	struct mailbox *p = &mb;
	memcpy((char *)p->msg, (char *)p->data, SHAREDMSG_SZ);
	return;
}

struct sharedmsg *build_message(const unsigned int forcednumber, const char *thismsg, size_t msglen)
{
	static struct sharedmsg msg; 
	
	memset((char *)&msg, 0, sizeof(msg));
	if(msglen > MAXLEN)
	{
	       printf("msglen will overflow maxlen: set to maxlen\n");
	       msglen = MAXLEN;
	}


	msg.forcednumber = forcednumber;
	memcpy((char *) &msg.msg, thismsg, msglen); 
	return &msg;
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


