#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* 
 * Test Case: 1
 * Test Criteria: The RSS result from your kernel module output should be
 * 1 GB (5 pts), 2 GB (5 pts), and 3 GB (5 pts), every 10 seconds for 30 seconds
 */

int rss_test_case() 
{
	int *array;
	int *new_array;
	int count 	= 0;
	int wss_range 	= 0;
	int mem_size 	= 268435456; //268435456*sizeof(int) = 1GB
	wss_range 	= mem_size;
	array 		= (int *) calloc (wss_range, sizeof(int));

	printf("[NOTE] The RSS & Swap values reported by the TESTSCRIPT and the Kernel module should match.\n");
	printf("[NOTE] The WSS value expected by the USERSPACE and the Kernel module should match.\n");
	printf("----------------------------------------------------------------------------------\n");

	printf("[USERSPACE]  [PID-%i] Expected WSS:%ld KB\n", getpid(), (wss_range*sizeof(int)/1024));

	while (count <=2)
	{
		/* The userspace always walks a constant range of wss_range*/
		for (int i=0; i<wss_range; i++) 
			array[i] = i;

		sleep(10);
		count++;

		/* Use of calloc make sure that the RSS keeps on increasing */
		array 	= (int *) calloc (wss_range, sizeof(int));
	}
	return 0;
}

/* 
 * Test Case: 2 
 * Test Criteria: The WSS result from your kernel module output should be 3 GB (5 pts), 
 * 2 GB (5 pts), and 1 GB (5 pts), every 10 seconds for 30 seconds
 */

int wss_test_case() 
{
	int *array;
	int count 	= 3; 
	int range 	= 0;

	int mem_size	=  268435456; //268435456*sizeof(int) = 1GB
	int mem_size_3gb= 3 * 268435456; //3GB
	array 		= (int *) malloc (mem_size_3gb*sizeof(int));

	printf("[NOTE] The RSS & Swap values reported by the TESTSCRIPT and the Kernel module should match.\n");
	printf("[NOTE] The WSS value expected by the USERSPACE and the Kernel module should match.\n");
	printf("----------------------------------------------------------------------------------\n");

	if (array != NULL) 
	{

		/*The userspace walks the entire range of 3GB once to maksure sure RSS remains constant*/
		for (int i=0; i< mem_size_3gb; i++) 
			array[i] = i;

		while (count>=1)
		{
			/*The userspace walks a variable range of memory in each iteration to vary WSS*/
			range 	= count * mem_size;
			printf("[USERSPACE]  [PID-%i] Expected [RSS:%ld KB] [WSS:%ld KB]\n", getpid(), (mem_size_3gb*sizeof(int)/1024), (range*sizeof(int)/1024));
			for (int i=0; i<range; i++) 
				array[i] = i;

			sleep(10);
			count--;
		}
	}

	return 0;
}

 /* Test Case: 3. 
  * Test Criteria: The SWAP results from your kernel module should match with proc results with memory 
  * pressure of 3.5 GB (5 pts), 4 GB (5 pts), and 4.5 GB (5 pts) 
  */

int swap_test_case(float scalar)
{
	int *array_constant;
	int mem_size = 268435456; //268435456*sizeof(int) = 1GB	

	mem_size 	= scalar * mem_size;
	array_constant 	= (int *) malloc (mem_size*sizeof(int));

	if (array_constant != NULL) 
	{
		printf("[NOTE] The RSS & Swap value reported by the TESTSCRIPT and the Kernel module should match.\n");
		printf("----------------------------------------------------------------------------------\n");

		while (1)
		{
			for (int i=0; i<mem_size; i++) 
				array_constant[i] = i;

			sleep(1);
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{

	volatile float scalar;
	volatile int test_case = 1;

	if( argc == 2 || argc == 3) 
	{
		/*
		 * Test Case 1 and Test Case 2 expects only one argument. Test Case Number
		 * Test Case 3 expects two arguments, Test Case Number and Scaling Factor 
		 */
		test_case = atoi(argv[1]);
		printf("[USERSPACE] [PID-%i] Executing Test Case: %d \n", getpid(), test_case);

		if(test_case == 3)
			scalar = atof(argv[2]);
	} else 
	{
		printf("Usage:\n");
		printf("%s <test-case-#>\n", argv[1]);
		exit(1);
	}

	switch(test_case) 
	{
		case 1:
			rss_test_case();
			break;
		case 2:
			wss_test_case();
			break;
		case 3:
			swap_test_case(scalar);
			break;
	}
	return 0;
}
