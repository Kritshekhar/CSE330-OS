# CSE330: Operating Systems 

Please follow the below steps to test your Project-3. 

- Download the zip of this git repository.
- Unzip the repository.
- Copy your kernel module code (memory_manager.c) to this repository.
- Run the test.sh script with the test arguments. 

bash test.sh < Test Case Number> 

## Test Cases:

| Test Case #   | Test Command  | Test Criteria  | Total Points |
| ------------- |:-------------:| :-----:|:-----:|
| 0 | NA | For all the test cases (1-3), the kernel module should init successfully with the new process PID and exit successfully.| 5 |
| 1 | ./test.sh 1 | The RSS result from your kernel module output should be 1 GB (5 pts), 2 GB (5 pts), and 3 GB (5 pts), every 10 seconds for 30 seconds | 15 |
| 2 | ./test.sh 2 | The WSS result from your kernel module output should be 3 GB (5 pts), 2 GB (5 pts), and 1 GB (5 pts), every 10 seconds for 30 seconds | 15 |
| 3 | ./test.sh 3 | The SWAP results from your kernel module should match with proc results with memory pressure of 3.5 GB (5 pts), 4 GB (5 pts), and 4.5 GB (5 pts)|15|

## Note: 
- Make sure you name your kernel model as "memory_manager" and name your module input parameter as "pid"
- Please do not make any changes in provided test code to pass the test cases.
- You can use print statements in case you want to debug and understand the logic of the test code.
- Please get in touch with the TAs if you face issues in using the test scripts.
