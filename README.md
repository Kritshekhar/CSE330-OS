# CSE330-OS 

##  STEP 1: Spawn "N" number of child processes 
  
  - Run the script start_process_gen.sh in Terminal-1 
  - **Input Argument** 
    - "N" - How many number of process you want to spawn.
  - The script will create a dummy user account "test_cse330" and spawn N number of child processes for the user.
  - Take a Note of the UID assigned to the user - "test_cse330"

```
yitao@yitao-VirtualBox:~/CSE330-OS$ ./start_process_gen.sh 10
```

#### Sample Output
```
passwd: password expiry information changed.  
Please use this UID for testing: 1005  
cc    -c -o process_generator.o process_generator.c  
cc -o process_generator process_generator.o -lpthread 
Process-10 Pid 136033  
Process-9 Pid 136034  
Process-8 Pid 136035  
Process-7 Pid 136036  
Process-6 Pid 136037  
Process-5 Pid 136038  
Process-4 Pid 136039  
Process-2 Pid 136041  
Process-1 Pid 136042  
Process-3 Pid 136040  
```

##  STEP 2: Test your Producer Consumer Kernel Module

  - Run the script test.sh .sh in Terminal-2
  - **Input Arguments**: 
    - uid - The UID of the dummy user "test_cse330"
    - buff_size - The size of the buffer
    - p - Number of Producer threads
    - c - Numner of Consumer threads
