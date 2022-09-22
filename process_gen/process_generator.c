#define _GNU_SOURCE  
#include <linux/sched.h>   
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int no_of_process=1;

int get_batch_size(int nprocesses)
{
	if (nprocesses > 0 && nprocesses <= 10)
		return 1;
	else if(nprocesses > 10 && nprocesses <= 100)
		return 10;
	else 
		return 100;
}

void create_batch_process(int nprocesses)
{
    pid_t pid;
    int status = -1;
    while(nprocesses > 0)
    {

	    if((pid = fork()) == 0)
	    {
		    printf("UID:%d Process-%d Pid %d\n", getuid(), no_of_process, getpid());
		    pause();
	    } else if(pid > 0)
	    {
		    nprocesses--;
		    no_of_process++;
	    }
    }
}


void create_process(int nprocesses, int batch_size)
{
	int num_of_batch = nprocesses/batch_size;
    int left_over	 = nprocesses%batch_size;

	//printf("Total number of child process to be spawned:%d\n", nprocesses);
	//printf("The calculated batch_size:%d\n", batch_size);
	//printf("Total number of batches:%d\n",num_of_batch);
	//printf("Total number of spill over processes:%d\n", left_over);
	
	for(int i=0; i<num_of_batch; i++)
	{
		create_batch_process(batch_size);
		sleep(1);
	}

	if (left_over)
		create_batch_process(left_over);
}

int main(int argc, char *argv[])
{
	int num;
	FILE *fp;
	char buffer[10];
	int batch_size;
	
	fp = fopen("var", "r");
	fread(buffer, 10, 1, fp);
	num         = atoi(buffer);
	batch_size  = get_batch_size(num);
	create_process(num, batch_size);
	fclose(fp);
	wait(NULL);
	return 0;
}
