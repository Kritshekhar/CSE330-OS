/*
 * This program creates processes as specified in the first argument
 * and then waits to be killed
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void init_process(int nprocesses)
{
    pid_t pid;

    if(nprocesses > 0)
    {
        if ((pid = fork()) < 0)
        {
            perror("error");
        }
        else if (pid == 0)
        {
	    printf("Process-%d Pid %d\n", nprocesses, getpid());
        }
        else if(pid > 0)
        {
            init_process(nprocesses - 1);
        }
    }
}

int main(int argc, char *argv[])
{
	int child;
	int num;
	FILE *fp;
	char buffer[10];
	
	fp = fopen("var", "r");
	fread(buffer, 10, 1, fp);
	num = atoi(buffer);
	init_process(num);
	fclose(fp);
	while(1) {
		
	}	
	return 0;
}
