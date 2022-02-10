/*
 * This program creates 8 processes with different scheduling policies
 * and 4 Batch policy (B).
 */
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>

#define CURR_THREAD 0

int main(void)
{
	int ret, ret_child_1, ret_child_2, ret_child_3;
	struct sched_param param;

	/*
	 * Retrieves the scheduling parameters from the current process.
	 */
	ret = sched_getparam(CURR_THREAD, &param);

	/*
	 * Call fork() to create a child process. You now have two processes. 
	 */
	ret_child_1 = fork();

	/*
	 * The fork() system call returns 0 to the child process and the pid to the 
	 * parent process.
	 */
	if (ret_child_1 == 0){
		printf("Child 1-%d. My pid is %d and my parent's pid is %d\n", getpid(), 
			getpid(), getppid());
		
	 	param.sched_priority = 98;
		
		/*
		 * Change the child 1 process to FIFO scheduling policy.
		 * The sched_setscheduler() returns 0 on success and -1 on failure.
		 */
		if (sched_setscheduler(CURR_THREAD, SCHED_FIFO, &param) == -1) {
			fprintf(stderr, "error setting scheduler, maker sure you are root\n");
		}
	}

	/*
	 * Call fork() to create a child process. You now have four processes. 
	 */
	ret_child_2 = fork();

	if (ret_child_2 == 0){
		printf("Child 2-%d. My pid is %d and my parent's pid is %d\n", getpid(), 
			getpid(), getppid());
		param.sched_priority = 97;

		/*
		 * Change the child 2 processes to Round Robin scheduling policy.
		 */
		if (sched_setscheduler(CURR_THREAD, SCHED_RR, &param) == -1) {
			fprintf(stderr, "error setting scheduler, maker sure you are root\n");
		}
	
	}

	/*
	 * Finally, we call fork() again. You now have eight processes.
	 */
	ret_child_3 = fork();
	if (ret_child_3 == 0){
		printf("Child 3-%d. My pid is %d and my parent's pid is %d\n", getpid(), 
			getpid(), getppid());
		param.sched_priority = 0;
		
		/*
		 * Change the child 3 processes to batch.
		 */
		if (sched_setscheduler(CURR_THREAD, SCHED_BATCH, &param) == -1) {
			fprintf(stderr, "error setting scheduler, maker sure you are root\n");
		}
	}
	
	/*
	 * Sleep for 30 seconds so that you can check the result with another 
	 * terminal.
	 */
	sleep(30);
	
	return 0;
}
