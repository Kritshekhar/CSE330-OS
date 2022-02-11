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
       	    printf("2");
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

void create_process(int num)
{
	for (int i = 1; i <= num; i++) {
		if (fork() == 0) {
	    		printf("Process-%d Pid %d\n", i, getpid());
			exit(0);
		}
	}
}

int main(int argc, char *argv[])
{
	int child;
	int num;
	FILE *fp;
	char buffer[10];
	
	//num = 5;
	//num = atoi(argv[1]);
	char *user_add_cmd="cat var";
	fp = fopen("var", "r");
	fread(buffer, 10, 1, fp);
    	//num = printf(system(user_add_cmd));
	//num = 5;
	//printf("%s\n", buffer);
	num = atoi(buffer);
	//create_process(num);
	init_process(num);
	fclose(fp);
	while(1) {
		
	}	
	return 0;
}
