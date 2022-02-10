/*
 * This program creates 8 processes with different scheduling policies
 * and 4 Batch policy (B).
 */
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <string.h> //to use strcpy()

#define CURR_THREAD 0

int main(void)
{
	char *user_add_cmd="sudo useradd test-cse330";
	printf("ls command...\n");
	char *get_uid_cmd = "id -u test-cse330";
	system(user_add_cmd);
	system(get_uid_cmd);
	return 0;
}
