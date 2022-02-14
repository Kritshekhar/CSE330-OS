# CSE330: Operating Systems 

Please follow the below steps to test your projects. 

##  STEP 1: Spawn "N" number of child processes 
  
  - Run the script start_process_gen.sh in Terminal-1 
  - **Input Argument** 
    - "N" - How many number of child process you want to spawn.
  - The script will create a dummy user account "test_cse330" and spawn N number of child processes for the user.
  - Take a Note of the UID assigned to the user - "test_cse330". In this example UID of the test_cse330 is 1005.

```
cse330@cse330:~/CSE330-OS$ ./start_process_gen.sh 10
```

#### Sample Output
```
passwd: password expiry information changed.  
Please use this UID for testing: 1005  
cc    -c -o process_generator.o process_generator.c  
cc -o process_generator process_generator.o -lpthread 
UID:1005 Process-10 Pid 136033  
UID:1005 Process-9 Pid 136034  
UID:1005 Process-8 Pid 136035  
UID:1005 Process-7 Pid 136036  
UID:1005 Process-6 Pid 136037  
UID:1005 Process-5 Pid 136038  
UID:1005 Process-4 Pid 136039  
UID:1005 Process-2 Pid 136041  
UID:1005 Process-1 Pid 136042  
UID:1005 Process-3 Pid 136040  
```

##  STEP 2: Test your Producer Consumer Kernel Module

  - Run the script test.sh .sh in Terminal-2
  - **Input Arguments**: 
    - uid - The UID of the dummy user "test_cse330". In this example the UID is 1005
    - buff_size - The size of the buffer
    - p - Number of Producer threads
    - c - Numner of Consumer threads
  - The name of the kernel module **MUST** be "producer_consumer"


```
cse330@cse330:~/Downloads/CSE330/project_2$ ./test.sh 1005 5 1 1
make -C /lib/modules/5.15.9KritshekharJha/build/ M=/home/cse330/Downloads/CSE330/project_2 modules
make[1]: Entering directory '/home/cse330/Downloads/linux-5.15.9'
make[1]: Leaving directory '/home/cse330/Downloads/linux-5.15.9'
[165830.147436] [Consumer-1] Consumed Item#-12 on buffer index:1 PID:136042        Elapsed Time-0:0:8 
[165830.148373] Producer Thread Received KILL Signal: Producer Stopped. Total # of Items produced:12
[165830.148391] The total elapsed time of all processes for UID 1005 is    0:1:36  
[165830.148393] Consumer Thread Received KILL Signal: Consumer Stopped. Total # of Items consumed:12
[165830.148404] CSE330 Project 2 Kernel Module Removed
Total Elapsed Time from PS Command 0:1:36
```

## Note: 
- Please do not make any changes in provided test code to pass the test cases.
- You can use print statements in case you want to debug and understand the logic of the test code.
- Please get in touch with the TAs if your find any bug in the test code.
